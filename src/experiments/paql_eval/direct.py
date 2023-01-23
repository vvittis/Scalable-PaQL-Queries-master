# coding=utf-8
from __future__ import division

from overrides.overrides import overrides

from src.dbms.db import DBConnection
from src.dbms.db import DBCursor
from src.dbms.dbms_settings import data_dbms_settings
from src.experiments.paql_eval.main import PaQLEvalExperiment
from src.paql.package_query import PackageQuery
from src.paql_eval.ilp_direct.ilp_direct import *
from src.paql_eval.search_process import *


class DirectExperiment(PaQLEvalExperiment):
    @property
    @overrides
    def description(self):
        return "Direct Algorithm experiment."

    @overrides
    def run(self, *args):
        # Set database where the input data reside
        self.set_datadb(DBCursor(DBConnection(**data_dbms_settings)))
        print(self.other_args)
        print(self.args)
        print("=" * 70)
        print("| NEW RUN {:<58}|".format(""))
        print("=" * 70)
        # os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
        print(self.args.query_file)

        q = PackageQuery.from_paql(open("testing/"+self.args.query_file).read())
        self.direct(q)

    def direct(self, q):
        # print(self.datadb.connection)
        # print(self._test_results_dir)
        # print(self.args.time_limit)
        # print(self.args.init_only)
        # print(self.args.mem_limit)
        # Direct Algorithm
        __init__kwargs = {
            "use_connection": self.datadb.connection,
        }
        init_kwargs = {
            "query": q,
            "store_lp_problems_dir": self._test_results_dir,
        }
        search_kwargs = {
            "timelimit": self.args.time_limit
        }
        results = get_optimal_package_in_subprocess_and_monitor_memory_usage(
                ILPDirect, __init__kwargs, init_kwargs, search_kwargs, self.args.init_only, self.args.mem_limit)

        self.end(results)


tests = [
    DirectExperiment,
]
