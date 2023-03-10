# #!/usr/bin/env python
# import os
# import signal
# import subprocess
# import sys
# from argparse import ArgumentParser
# from time import sleep
# from scipy.stats import *
# import numpy as np
# import psycopg2
# import scipy
# from IPython.core.display import display
#
# from Parser import *
# import pandas as pd
#
# # PROGRAM VARIABLES
# # INITIAL_SIZE = 100
# # STEP = 100
# # global experiment_name
# # global query_file
# #
# #
# # def init():
# #     # Parse arguments
# #     experiment_name = "exp_" + input("Experiment")
# #     query_file = input("query") + ".paql"
# #     initial_size = int(input("initial size"))
# #     step = int(input("step"))
#
# # SEEDS = [0, 4, 5, 7, 3, 11, 14, 2, 20, 18]
# # SEEDS = [29, 21, 16, 6, 0, 4, 5, 3, 11, 2]
#
# SEEDS = [96, 25, 77, 99, 29, 21, 16, 0, 4, 3]
#
#
# def take_input():
#     print('Do you have a conf already?')
#     conf_option = input()
#     if conf_option == 'y':
#         experiment_name = "exp_1"
#         step = "100"
#         initial_size = "100"
#         query_file = "q4.paql"
#         complete_where_clause = " exp_name = '" + experiment_name + "'" + " AND query_file = '" + query_file + "'" + " AND initial_size = '" + initial_size + "'" + " AND step = '" + step+ "'"
#     else:
#         # Experiment number
#         print('Enter the experiment number: ')
#         experiment_answer = input()
#         if experiment_answer == '*':
#             experiment_clause = ' '
#         else:
#             experiment_clause = " exp_name = '" + experiment_answer + "'"
#
#         # query file
#         print('Enter the query_file: ')
#         query_answer = input()
#         if query_answer == '*':
#             query_file_clause = ''
#         else:
#             query_file_clause = " AND query_file = '" + query_answer + "'"
#
#         # initial size
#         print('Enter the initial size: ')
#         initial_size_answer = input()
#         if initial_size_answer == '*':
#             initial_size_clause = ''
#         else:
#             initial_size_clause = " AND initial_size = '" + initial_size_answer + "'"
#
#         # step size
#         print('Enter the step size: ')
#         step_size_answer = input()
#         if step_size_answer == '*':
#             step_size_clause = ' '
#         else:
#             step_size_clause = " AND step = '" + step_size_answer + "'"
#
#         complete_where_clause = experiment_clause + query_file_clause + initial_size_clause + step_size_clause
#         print(complete_where_clause)
#
#     return complete_where_clause
#
#
# def setup_tests():
#     # experiment_name = "'exp_1'"
#     # step = "'100'"
#     # initial_size = "'100'"
#     # query_file = "'q4.paql'" #q10.paql
#
#     complete_where_clause = take_input()
#
#     connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
#     cursor = connection.cursor()
#     # execute query
#     # print(experiment_name)
#
#     # experiments = pd.read_sql_query('select * from "exp" where exp_name = ' + experiment_name, con=connection)
#     experiments = pd.read_sql_query(
#         'select * from "exp" where ' + complete_where_clause, con=connection)
#     # 'select * from "exp" where exp_name = ' + experiment_name,con=connection)
#     print('select * from "exp" where ' + complete_where_clause)
#     experiment_dataframe = pd.DataFrame(experiments).sort_values('id')
#     print(experiment_dataframe)
#
#     for index, row in experiment_dataframe.iterrows():
#         obj = read_query(row.query_file)
#         # acc_incremental_packagebuilder_testing(obj, row.id, row.exp_name, row.query_file, row.initial_size, row.step)
#         incremental_packagebuilder_testing(obj, row.id, row.exp_name, row.query_file, row.initial_size, row.step)
#         # incremental_direct_testing(obj, row.id, row.exp_name, row.query_file, row.initial_size, row.step)
#         # after the experiment is done, delete results table
#
#
# def read_query(query_file):
#     # os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
#     with open("queries/" + query_file, "r") as input:
#         # Creating "gfg output file.txt" as output
#         # file in write mode
#         with open("query.paql", "w") as output:
#             # Writing each line from input file to
#             # output file using loop
#             for line in input:
#                 output.write(line)
#                 objective = line[0:3]
#                 if objective == 'MIN':
#                     print("MIN")
#                 elif objective == 'MAX':
#                     print("MAX")
#     return objective
#
#
# # connection with database Diet
# def incremental_packagebuilder_testing(obj, exp_id, exp_name, query_file, initial_size, step):
#     """
#     For each experiment:
#     The steps are the following:
#     1. Read the total number of rows of the original table.
#     2. Read from the original table and insert into the intermediate table.
#        If we are in the first iteration then read only from 0 to initial_size.
#        If we are in other iteration then read from where we left +step.
#     3. Call Direct based on intermediate table. Pass all arguments, so it can write to results table.
#     4. Read package from results table (package = opt_combo).
#     5. Delete whatever exists in intermediate table.
#     6. Add package to intermediate table and make sure the temp_id is correct.
#     """
#     global objective_value
#     connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
#     cursor = connection.cursor()
#     # execute query
#     count_lines = pd.read_sql_query('select count(*) from "diet"', con=connection)
#
#     dataset = pd.read_sql_query(
#         'select * from "diet" where id between (0) and (' + str(int(count_lines.values)) + ')',
#         con=connection)
#     connection.commit()
#     df = pd.DataFrame(dataset)
#     seeds = pd.DataFrame(SEEDS)
#     result_table = []
#     number_of_packages_table = []
#     input_data_size = []
#     result_idx = 0
#     for index, row in seeds.iterrows():
#         if obj == 'MAX':
#             objective_value = 0
#         elif obj == 'MIN':
#             objective_value = 999999
#         temp_result_table = np.array([])
#         temp_input_data_size = np.array([])
#         temp_number_package_table = np.array([])
#         print(row.values)
#         randomstate = int(row.values)
#         print(randomstate)
#         shuffled_dataset = df.sample(frac=1, random_state=randomstate).reset_index()
#         # shuffled_dataset = df
#         print(shuffled_dataset.head())
#         index1 = 1
#         package_df = pd.DataFrame()
#         total_packages = 0
#         for i in range(initial_size, int(count_lines.values), step):
#             # Read new data
#             if i == initial_size:
#                 print("Initial Phase Size: " + str(initial_size))
#                 inter_dataframe = shuffled_dataset[0:initial_size].sort_values(by=['id'])
#                 # print(inter_dataframe)
#                 print("Insertion to intermediate table from 1 to " + str(initial_size) + ". Done")
#             else:
#                 print("Incremental step")
#                 temp_df = [package_df, shuffled_dataset[i - step: i]]
#                 result = pd.concat(temp_df)
#                 inter_dataframe = result.sort_values(by=['id']).reset_index()
#                 # display(inter_dataframe.to_string())
#                 print("Insertion to intermediate table from " + str(i - step + 1) + " to " + str(i) + ". Done")
#             # Add new data to intermediate table
#             for inter_index, inter_row in inter_dataframe.iterrows():
#                 # print(inter_row.id , inter_row.fat , inter_row.protein, inter_row.carbs , inter_row.calories)
#                 cursor.execute(
#                     'insert into inter_diet_table (id,fat,protein,carbs,calories,cost,temp_id) VALUES( %s, %s, %s, %s, %s, %s ,%s)',
#                     (str(int(inter_row.id)), str(int(inter_row.fat)), str(int(inter_row.protein)),
#                      str(int(inter_row.carbs)),
#                      str(int(inter_row.calories)), str(int(inter_row.cost)),
#                      str(index1)))
#                 index1 += 1
#             index1 = 1
#             sleep(1)
#             connection.commit()
#             # keep track of the input size to DIRECT
#             temp_input_data_size = np.append(temp_input_data_size, len(inter_dataframe))
#             # Execute Package Builder
#             call_direct(exp_id, exp_name, query_file, initial_size, step, 'IPM_')
#             print("Executing Package Builder, Method Direct. Done")
#             # Read data from results table
#             last_line = ""
#             # os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
#             output_file = "results/IPM_n" + str(exp_id) + "" + str(exp_name) + "i" + str(
#                 initial_size) + "s" + str(
#                 step) + str(query_file) + ".txt"
#             # print(output_file)
#             with open(output_file) as f:
#                 for line in f:
#                     pass
#                 last_line = line
#             parsing_data = parser(last_line)
#             package_tuples = parsing_data[0]
#             temp_objective = int(float(parsing_data[1]))
#             package_size = int(parsing_data[2])
#             if package_size == 0:  # infeasibility
#                 raise ValueError('Infeasibility - Very bad thing happened.')
#             else:
#                 if temp_objective >= objective_value and obj == 'MAX':
#                     objective_value = temp_objective
#                     print("New objective is greater for step " + str(i))
#                 elif temp_objective <= objective_value and obj == 'MIN':
#                     objective_value = temp_objective
#                 else:
#                     raise ValueError('A very specific bad thing happened.')
#             # temp_result_table.append(objective_value)
#             temp_number_package_table = np.append(temp_number_package_table, package_size)
#             temp_result_table = np.append(temp_result_table, objective_value)
#             my_str = ','.join(str(item) for item in package_tuples)
#             # print(package_tuples)
#             package = pd.read_sql_query('SELECT * FROM inter_diet_table WHERE temp_id IN (' + my_str + ')',
#                                         con=connection)
#             package_df = pd.DataFrame(package)
#             print(package_df)
#             # print(last_line)
#             print("Fetching data from Package Builder. Done")
#             # Delete all data with which you run Package Builder
#             cursor.execute(
#                 'delete from inter_diet_table')
#             connection.commit()
#             if i == initial_size:
#                 print("Deletion of intermediate table from 0 to " + str(initial_size) + ". Done")
#             else:
#                 print("Deletion of intermediate table from " + str(i - step + 1) + " to " + str(i) + ". Done")
#         os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
#         output_file = "testing/results/IPM_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#             step) + str(query_file) + ".txt"
#         open(output_file, "w")
#         print(temp_result_table)
#         input_data_size.append(temp_input_data_size)
#         number_of_packages_table.append(temp_number_package_table)
#         result_table.append(temp_result_table)
#         print(str(result_table))
#     result_table = np.array(result_table)
#     input_data_size = np.array(input_data_size)
#     number_of_packages_table = np.array(number_of_packages_table)
#     output_file = "testing/results/IPM_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#         step) + str(query_file) + ".txt"
#     with open(output_file, "a") as myfile:
#         for table in result_table:
#             for metric in table:
#                 myfile.write(str(metric) + " ")
#             myfile.write("\n")
#     myfile.close()
#     result_table = result_table.transpose()
#     input_data_size = input_data_size.transpose()
#     number_of_packages_table = number_of_packages_table.transpose()
#     output_file = "testing/results/IPM_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#         step) + str(query_file) + "_final_metrics.txt"
#     with open(output_file, "a") as myfile:
#         for (data, packages, data_size) in zip(result_table, number_of_packages_table, input_data_size):
#             print(data)
#             # package_len = len(np.array(packages[packages != 0]))
#             package_len = len(packages)
#             # data = np.array(data[data != -1])
#             # data[data == 99999] = 0
#             mean_data_size = round(scipy.mean(data_size), 2)
#             mean_value_obj = round(scipy.mean(data), 2)
#             count_obj = len(data)
#             stderror_obj = round(sem(data), 2)  # standard error of the mean
#             myfile.write(str(mean_value_obj) + "," + str(stderror_obj) + "," + str(package_len) + "," + str(
#                 mean_data_size) + "\n")
#     myfile.close()
#
#
# def call_direct(experiment_id, experiment_name, query_file, initial_size, step, function, sshtunnel=None,
#                 callback=None):
#     """
#     call direct()
#     This function calls the direct method through a pipe.
#     The goal of this function is to explicitly dictate what the DIRECT function should execute.
#     DISCLAIMER: The whole project "listens" to the inter_diet_table.
#     Also, it is the job of call_direct to write to results table the results of each individual test.
#     That's why we send the all the parameters needed (exp_name,query_file,data_size)
#     """
#
#     args = ['/usr/bin/env', 'python', '-m', 'src.experiments.run_experiments', '--run-now', 'paql_eval', 'direct',
#             '-q', 'query.paql', str(experiment_id), experiment_name, query_file, str(initial_size), str(step),
#             str(function)]
#     print("Inside here len(args) " + str(args))
#     p = subprocess.Popen(args, env=os.environ, shell=False)  # calls run_experiments.py
#     print(p.args)
#     # a = dir(p)
#     # print(a)
#     while p.poll() is None:
#         try:
#             print("1")
#             p.wait()
#
#         except (KeyboardInterrupt, SystemExit) as e:
#             print((KeyboardInterrupt, SystemExit))
#             print("lol")
#             p.send_signal(signal.SIGINT)
#             # p.wait()
#             if sshtunnel is not None:
#                 sshtunnel.close()
#                 sshtunnel = None
#             sys.exit(-1)
#
#         except Exception as e:
#             print(Exception)
#             p.send_signal(signal.SIGTERM)
#             # p.wait()
#             if sshtunnel is not None:
#                 sshtunnel.close()
#                 sshtunnel = None
#             raise e
#
#     if callback is not None:
#         callback()
#
#     if sshtunnel is not None:
#         sshtunnel.close()
#         sshtunnel = None
#
#
# def incremental_direct_testing(obj, exp_id, exp_name, query_file, initial_size, step):
#     global objective_value1
#     connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
#     cursor = connection.cursor()
#     data_size = pd.read_sql_query('select count(*) from "diet"', con=connection)
#     index2 = 1
#
#     dataset = pd.read_sql_query(
#         'select * from "diet" where id between (0) and (' + str(int(data_size.values)) + ')',
#         con=connection)
#     df = pd.DataFrame(dataset)
#     seeds = pd.DataFrame(SEEDS)
#     number_of_packages_table = []
#     result_table = []
#     input_data_size = []
#     result_idx = 0
#     for index, row in seeds.iterrows():
#         randomstate = int(row.values)
#         print(randomstate)
#         shuffled_dataset = df.sample(frac=1, random_state=randomstate).reset_index()
#         temp_result_table = np.array([])
#         temp_input_data_size = np.array([])
#         temp_number_package_table = np.array([])
#         if obj == 'MAX':
#             objective_value1 = 0
#         elif obj == 'MIN':
#             objective_value1 = 999999
#         for i in range(initial_size, int(data_size.values), step):
#
#             if i == initial_size:
#                 print("Initial Phase Size: " + str(initial_size))
#                 inter_dataframe = shuffled_dataset[0:initial_size].sort_values(by=['id'])
#                 print("Insertion to intermediate table from 1 to " + str(initial_size) + ". Done")
#             else:
#                 print("Incremental step")
#                 inter_dataframe = shuffled_dataset[0: i].sort_values(by=['id'])
#                 print("Insertion to intermediate table from 0 to " + str(i) + ". Done")
#             # print(inter_dataframe)
#             for index, row in inter_dataframe.iterrows():
#                 cursor.execute(
#                     'insert into inter_diet_table (id,fat,protein,carbs,calories,cost,temp_id) VALUES( %s, %s, %s, %s, %s, %s ,%s)',
#                     (str(row.id), str(row.fat), str(row.protein), str(row.carbs), str(row.calories), str(row.cost),
#                      str(index2)))
#                 index2 += 1
#             connection.commit()
#             # Call direct
#             # keep track of the input size to DIRECT
#             temp_input_data_size = np.append(temp_input_data_size, len(inter_dataframe))
#             # Execute Package Builder
#             call_direct(exp_id, exp_name, query_file, initial_size, step, 'D_')
#             print("Executing Package Builder, Method Direct. Done")
#             # Read data from results table
#             last_line = ""
#             os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
#             output_file = "testing/results/D_n" + str(exp_id) + "" + str(exp_name) + "i" + str(
#                 initial_size) + "s" + str(
#                 step) + str(query_file) + ".txt"
#             # print(output_file)
#             with open(output_file) as f:
#                 for line in f:
#                     pass
#                 last_line = line
#             parsing_data = parser(last_line)
#             package_tuples = parsing_data[0]
#             temp_objective = int(float(parsing_data[1]))
#             package_size = int(parsing_data[2])
#             if package_size == 0:
#                 raise ValueError('Infeasibility - A very specific bad thing happened.')
#                 # objective_value1 = 0
#             else:
#                 if temp_objective >= objective_value1 and obj == 'MAX':
#                     objective_value1 = temp_objective
#                     print("New objective is greater for step " + str(i))
#                 elif temp_objective <= objective_value1 and obj == 'MIN':
#                     objective_value1 = temp_objective
#                 else:
#                     raise ValueError('A very specific bad thing happened.')
#             temp_number_package_table = np.append(temp_number_package_table, package_size)
#             temp_result_table = np.append(temp_result_table, objective_value1)
#             # Delete all data with which you run Package Builder
#             cursor.execute('delete from inter_diet_table')
#             connection.commit()
#             if i == initial_size:
#                 print("Deletion of intermediate table from 0 to " + str(initial_size) + ". Done")
#             else:
#                 print("Deletion of intermediate table from 0 to " + str(i) + ". Done")
#         os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
#         output_file = "testing/results/D_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#             step) + str(query_file) + ".txt"
#         open(output_file, "w")
#         print(temp_result_table)
#         input_data_size.append(temp_input_data_size)
#         number_of_packages_table.append(temp_number_package_table)
#         result_table.append(temp_result_table)
#         print(str(result_table))
#     result_table = np.array(result_table)
#     input_data_size = np.array(input_data_size)
#     number_of_packages_table = np.array(number_of_packages_table)
#     output_file = "testing/results/D_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#         step) + str(query_file) + ".txt"
#     with open(output_file, "a") as myfile:
#         for table in result_table:
#             for metric in table:
#                 myfile.write(str(metric) + " ")
#             myfile.write("\n")
#     myfile.close()
#     result_table = result_table.transpose()
#     input_data_size = input_data_size.transpose()
#     number_of_packages_table = number_of_packages_table.transpose()
#     output_file = "testing/results/D_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#         step) + str(query_file) + "_final_metrics.txt"
#     open(output_file, "w")
#     with open(output_file, "a") as myfile:
#         for (data, packages, data_size) in zip(result_table, number_of_packages_table, input_data_size):
#             print(data)
#             package_len = len(packages)
#             # package_len = len(np.array(packages[packages != 0]))
#             # data = np.array(data[data != -1])
#             # data[data == 99999] = 0
#             mean_data_size = round(scipy.mean(data_size), 2)
#             mean_value_obj = round(scipy.mean(data), 2)
#             count_obj = len(data)
#             stderror_obj = round(sem(data), 2)  # standard error of the mean
#             myfile.write(str(mean_value_obj) + "," + str(stderror_obj) + "," + str(package_len) + "," + str(
#                 mean_data_size) + "\n")
#     myfile.close()
#
#
# # connection with database Diet
# def acc_incremental_packagebuilder_testing(obj, exp_id, exp_name, query_file, initial_size, step):
#     """
#     For each experiment:
#     The steps are the following:
#     1. Read the total number of rows of the original table.
#     2. Read from the original table and insert into the intermediate table.
#        If we are in the first iteration then read only from 0 to initial_size.
#        If we are in other iteration then read from where we left +step.
#     3. Call Direct based on intermediate table. Pass all arguments, so it can write to results table.
#     4. Read package from results table (package = opt_combo).
#     5. Delete whatever exists in intermediate table.
#     6. Add package to intermediate table and make sure the temp_id is correct.
#     """
#     global objective_value
#     connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
#     cursor = connection.cursor()
#     # execute query
#     count_lines = pd.read_sql_query('select count(*) from "diet"', con=connection)
#
#     dataset = pd.read_sql_query(
#         'select * from "diet" where id between (0) and (' + str(int(count_lines.values)) + ')',
#         con=connection)
#     df = pd.DataFrame(dataset)
#     seeds = pd.DataFrame(SEEDS)
#     result_table = []
#     number_of_packages_table = []
#     input_data_size = []
#     result_idx = 0
#     for index, row in seeds.iterrows():
#         if obj == 'MAX':
#             objective_value = 0
#         elif obj == 'MIN':
#             objective_value = 999999
#         temp_result_table = np.array([])
#         temp_input_data_size = np.array([])
#         temp_number_package_table = np.array([])
#         print(row.values)
#         randomstate = int(row.values)
#         print(randomstate)
#         shuffled_dataset = df.sample(frac=1, random_state=randomstate).reset_index()
#         # shuffled_dataset = df
#         print(shuffled_dataset.head())
#         index1 = 1
#         package_df = pd.DataFrame()
#         total_packages = 0
#         for i in range(initial_size, int(count_lines.values), step):
#             # Read new data
#             if i == initial_size:
#                 print("Initial Phase Size: " + str(initial_size))
#                 inter_dataframe = shuffled_dataset[0:initial_size].sort_values(by=['id'])
#                 # print(inter_dataframe)
#                 print("Insertion to intermediate table from 1 to " + str(initial_size) + ". Done")
#             else:
#                 print("Incremental step")
#                 temp_df = [package_df, shuffled_dataset[i - step: i]]
#                 result = pd.concat(temp_df)
#                 inter_dataframe = result.sort_values(by=['id']).reset_index()
#                 # display(inter_dataframe.to_string())
#                 print("Insertion to intermediate table from " + str(i - step + 1) + " to " + str(i) + ". Done")
#             # Add new data to intermediate table
#             for inter_index, inter_row in inter_dataframe.iterrows():
#                 # print(inter_row.id , inter_row.fat , inter_row.protein, inter_row.carbs , inter_row.calories)
#                 cursor.execute(
#                     'insert into inter_diet_table (id,fat,protein,carbs,calories,cost,temp_id) VALUES( %s, %s, %s, %s, %s, %s ,%s)',
#                     (str(int(inter_row.id)), str(int(inter_row.fat)), str(int(inter_row.protein)),
#                      str(int(inter_row.carbs)),
#                      str(int(inter_row.calories)), str(int(inter_row.cost)),
#                      str(index1)))
#                 index1 += 1
#             index1 = 1
#             sleep(1)
#             connection.commit()
#             # keep track of the input size to DIRECT
#             temp_input_data_size = np.append(temp_input_data_size, len(inter_dataframe))
#             # Execute Package Builder
#             call_direct(exp_id, exp_name, query_file, initial_size, step, 'ACC_')
#             print("Executing Package Builder, Method Direct. Done")
#             # Read data from results table
#             last_line = ""
#             os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
#             output_file = "testing/results/ACC_n" + str(exp_id) + "" + str(exp_name) + "i" + str(
#                 initial_size) + "s" + str(
#                 step) + str(query_file) + ".txt"
#             # print(output_file)
#             with open(output_file) as f:
#                 for line in f:
#                     pass
#                 last_line = line
#             parsing_data = parser(last_line)
#             package_tuples = parsing_data[0]
#             temp_objective = int(float(parsing_data[1]))
#             package_size = int(parsing_data[2])
#             if package_size == 0:  # infeasibility
#                 raise ValueError('Infeasibility - Very bad thing happened.')
#             else:
#                 if temp_objective >= objective_value and obj == 'MAX':
#                     objective_value = temp_objective
#                     print("New objective is greater for step " + str(i))
#                 elif temp_objective <= objective_value and obj == 'MIN':
#                     objective_value = temp_objective
#                 else:
#                     raise ValueError('A very specific bad thing happened.')
#             # temp_result_table.append(objective_value)
#             temp_number_package_table = np.append(temp_number_package_table, package_size)
#             temp_result_table = np.append(temp_result_table, objective_value)
#             my_str = ','.join(str(item) for item in package_tuples)
#             # print(package_tuples)
#             package = pd.read_sql_query('SELECT * FROM inter_diet_table WHERE temp_id IN (' + my_str + ')',
#                                         con=connection)
#             package_temp = pd.DataFrame(package)
#             print(package_temp)
#             package_df = pd.concat([package_df, package_temp]).drop_duplicates(subset=['id']).sort_values(by=['id'])
#             print(package_df)
#             tt = len(package_df)
#             print(tt)
#             # package_df = pd.DataFrame(package)
#             # print(package_df)
#             # print(last_line)
#             print("Fetching data from Package Builder. Done")
#             # Delete all data with which you run Package Builder
#             cursor.execute('delete from inter_diet_table')
#             connection.commit()
#             if i == initial_size:
#                 print("Deletion of intermediate table from 0 to " + str(initial_size) + ". Done")
#             else:
#                 print("Deletion of intermediate table from " + str(i - step + 1) + " to " + str(i) + ". Done")
#         os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
#         output_file = "testing/results/ACC_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#             step) + str(query_file) + ".txt"
#         open(output_file, "w")
#         print(temp_result_table)
#         input_data_size.append(temp_input_data_size)
#         number_of_packages_table.append(temp_number_package_table)
#         result_table.append(temp_result_table)
#         print(str(result_table))
#     result_table = np.array(result_table)
#     input_data_size = np.array(input_data_size)
#     number_of_packages_table = np.array(number_of_packages_table)
#     output_file = "testing/results/ACC_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#         step) + str(query_file) + ".txt"
#     with open(output_file, "a") as myfile:
#         for table in result_table:
#             for metric in table:
#                 myfile.write(str(metric) + " ")
#             myfile.write("\n")
#     myfile.close()
#     result_table = result_table.transpose()
#     input_data_size = input_data_size.transpose()
#     number_of_packages_table = number_of_packages_table.transpose()
#     output_file = "testing/results/ACC_n" + str(exp_id) + "" + str(exp_name) + "i" + str(initial_size) + "s" + str(
#         step) + str(query_file) + "_final_metrics.txt"
#     with open(output_file, "a") as myfile:
#         for (data, packages, data_size) in zip(result_table, number_of_packages_table, input_data_size):
#             print(data)
#             # package_len = len(np.array(packages[packages != 0]))
#             package_len = len(packages)
#             # data = np.array(data[data != -1])
#             # data[data == 99999] = 0
#             mean_data_size = round(scipy.mean(data_size), 2)
#             mean_value_obj = round(scipy.mean(data), 2)
#             count_obj = len(data)
#             stderror_obj = round(sem(data), 2)  # standard error of the mean
#             myfile.write(str(mean_value_obj) + "," + str(stderror_obj) + "," + str(package_len) + "," + str(
#                 mean_data_size) + "\n")
#     myfile.close()
#
#
# if __name__ == "__main__":
#     # take_input()
#     setup_tests()
#     # incremental_packagebuilder_testing()
#     # incremental_direct_testing()
