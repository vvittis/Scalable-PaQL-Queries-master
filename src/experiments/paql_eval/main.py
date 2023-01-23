# coding=utf-8
from __future__ import division

from abc import ABCMeta

import psycopg2
from overrides.overrides import overrides
from pympler import tracker

from src.experiments.shared.experiment import Experiment
from src.paql_eval.exceptions import TimeLimitElapsed
from src.paql_eval.search_process import *
from src.paql_eval.sketch_refine.sketch_refine import *
from src.utils.log import *

PROCESS_RESIDENT_MEMORY_LIMIT = -1  # NO MEMORY LIMIT
# PROCESS_RESIDENT_MEMORY_LIMIT = 200 * 1024 * 1024 # 200 MB

SOLVING_TIME_LIMIT = None  # NO TIME LIMIT


# SOLVING_TIME_LIMIT = 60 * 15  # 15 minutes


class PaQLEvalExperiment(Experiment):
    __metaclass__ = ABCMeta

    @overrides
    def __init__(self, *args, **kwargs):
        super(PaQLEvalExperiment, self).__init__(*args, **kwargs)
        self.tracker = tracker.SummaryTracker()

    @overrides
    def set_args(self):
        super(PaQLEvalExperiment, self).set_args()

        # General arguments
        self.arg_parser.add_argument(
            "-q", "--query-file",
            required=True,
            help="The file containing the package query to evaluate.")
        self.arg_parser.add_argument(
            "--run-name", type=str, default="generic")
        self.arg_parser.add_argument(
            "-l", "--time-limit", type=float, default=SOLVING_TIME_LIMIT)
        self.arg_parser.add_argument(
            "--mem-limit", type=float, default=PROCESS_RESIDENT_MEMORY_LIMIT)
        self.arg_parser.add_argument(
            "--init-only", action="store_true",
            help="Set this if you only want to initialize the search method (e.g., only run partitioning), "
                 "but you don't want to evaluate the query.")

        # Defaults
        self.arg_parser.set_defaults(init_only=False)

    def end(self, results):
        # Get init results and merge with recovered init info
        print("WOW " + str(self.other_args))
        init_result = next(results)
        init_info = {}
        if "opt_init_info" in init_result:
            # Copy the new init results over to the existing init info
            for at in [a for a in dir(init_result["opt_init_info"]) if
                       not a.startswith('__') and not callable(getattr(init_result["opt_init_info"], a))]:
                if at not in init_info or init_info[at] is None or getattr(init_result["opt_init_info"],
                                                                           at) is not None:
                    init_info[at] = getattr(init_result["opt_init_info"], at)

        # Get run results
        run_result = next(results)
        if run_result["status"] == "exception":
            if run_result["exception"].__class__ == SubprocessKilled:
                success = False
                bt_status = "killed"
                candidate_combo = None
                candidate_obj_val = None
                runinfo = None
                log("Reduced Space Killed – probably used too much memory")
                log("Storing backtracking *failure* into experimental dbms...")
                print("Done.")

            elif run_result["exception"].__class__ == TimeLimitElapsed:
                success = False
                bt_status = "time elapsed: {}".format(self.args.time_limit)
                candidate_combo = None
                candidate_obj_val = None
                runinfo = run_result["opt_run_info"].strategy_run_info
                print("Reduced Space Time Limit Elapsed")

            elif run_result["exception"].__class__ == ReducedSpaceInfeasible:
                success = False
                bt_status = "reduced space infeasible"
                candidate_combo = None
                candidate_obj_val = None
                runinfo = run_result["opt_run_info"].strategy_run_info
                print("Reduced Space Infeasible -- w.h.p query is actually infeasible")

            elif run_result["exception"] == "init_only":
                success = False
                bt_status = None
                candidate_combo = None
                candidate_obj_val = None
                runinfo = None

            else:
                # Writing results to file
                if (len(self.other_args) > 0):
                    print(self.other_args)
                    exp_id = self.other_args[0]
                    print(exp_id)
                    exp_name = self.other_args[1]
                    query_file = self.other_args[2]
                    initial_size = self.other_args[3]
                    step = self.other_args[4]
                    function = self.other_args[5]
                    random_state = self.other_args[6]
                    iteration = self.other_args[7]
                    connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
                    cursor = connection.cursor()
                    table_name = "results_exp_id_" + str(exp_id)

                    if (len(self.other_args) > 0):
                        print("Random State " + random_state)
                        cursor.execute(
                            'insert into ' + table_name + ' (exp_id,seed,function, iteration,obj_value,solution, status,sol_size) VALUES( %s, %s, %s, %s, %s, %s, %s, %s)',
                            (int(exp_id), float(random_state), str(function), int(iteration), None,
                             None, bool(0),
                             int(0)))
                        connection.commit()
                raise Exception(run_result["exception"])

        elif run_result["status"] == "success":
            success = True
            bt_status = "success"
            candidate_combo = run_result["opt_combo"]
            candidate_obj_val = run_result["opt_obj_val"]
            runinfo = run_result["opt_run_info"]

        else:
            raise Exception("Unknown status '{}'".format(run_result["status"]))

        print()
        print("SUCCESS:", success)
        print("STATUS:", bt_status)
        print("SOL SIZE:", len(candidate_combo))
        print("SOLUTION:", candidate_combo)
        print("OBJ VAL:", candidate_obj_val)

        print(self.other_args)
        exp_id = self.other_args[0]
        print(exp_id)
        exp_name = self.other_args[1]
        query_file = self.other_args[2]
        initial_size = self.other_args[3]
        step = self.other_args[4]
        function = self.other_args[5]
        random_state = self.other_args[6]
        iteration = self.other_args[7]
        connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
        cursor = connection.cursor()
        table_name = "results_exp_id_" + str(exp_id)
        temp_cand = ",".join(str(x) for x in candidate_combo)


        if (len(self.other_args) > 0):
            print("Random State " + random_state)
            cursor.execute(
                'insert into ' + table_name + ' (exp_id,seed,function, iteration,obj_value,solution, status,sol_size) VALUES( %s, %s, %s, %s, %s, %s, %s, %s)',
                (int(exp_id), float(random_state), str(function), int(iteration), float(candidate_obj_val), temp_cand, bool(bt_status),
                 int(len(candidate_combo))))
            connection.commit()

        print("INIT INFO:\n", init_info)
        print()
        print("RUN INFO:\n", str(runinfo))
