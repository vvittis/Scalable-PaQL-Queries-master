#!/usr/bin/env python
import os
from time import sleep
import psycopg2
from Parser import *
import pandas as pd

# PROGRAM VARIABLES
INITIAL_SIZE = 500
STEP = 50


# connection with database Diet
def incremental_packagebuilder_testing():
    connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
    cursor = connection.cursor()
    # execute query
    count_lines = pd.read_sql_query('select count(*) from "diet"', con=connection)

    index1 = 1
    # Experiment 1
    for i in range(INITIAL_SIZE, int(count_lines.values), STEP):
        if i == INITIAL_SIZE:
            print("Initial Phase Size: " + str(INITIAL_SIZE))
            inter_table = pd.read_sql_query(
                'select * from "diet" where id between (0) and (' + str(INITIAL_SIZE) + ')',
                con=connection)
            print("Insertion to intermediate table from 1 to " + str(INITIAL_SIZE) + ". Done")
        else:
            print("Incremental step")
            inter_table = pd.read_sql_query(
                'select * from "diet" where id between (' + str(i - STEP + 1) + ') and (' + str(i) + ')',
                con=connection)
            print("Insertion to intermediate table from " + str(i - STEP + 1) + " to " + str(i) + ". Done")
        inter_dataframe = pd.DataFrame(inter_table)
        # print(inter_dataframe)
        for index, row in inter_dataframe.iterrows():
            cursor.execute(
                'insert into inter_diet_table (id,fat,protein,carbs,calories,cost,temp_id) VALUES( %s, %s, %s, %s, %s, %s ,%s)',
                (str(row.id), str(row.fat), str(row.protein), str(row.carbs), str(row.calories), str(row.cost),
                 str(index1)))
            index1 += 1
        index1 = 1
        connection.commit()
        sleep(1)
        # Execute Package Builder
        os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
        os.system('bin/pb set cfg/example.cfg')
        print("Executing Package Builder, Method Direct. Done")
        sleep(3)

        # Read data from output file
        last_line = ""
        os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
        with open('testing/results/I500S50/Q4.txt') as f:
            for line in f:
                pass
            last_line = line
        package_tuples = parser(last_line)[0]
        my_str = ','.join(str(item) for item in package_tuples)
        # print(package_tuples)
        package = pd.read_sql_query('SELECT * FROM inter_diet_table WHERE temp_id IN (' + my_str + ')', con=connection)
        package_df = pd.DataFrame(package)
        print(package_df)
        print(last_line)
        print("Fetching data from Package Builder. Done")
        sleep(1)
        # Delete all data with which you run Package Builder
        cursor.execute(
            'delete from inter_diet_table')
        connection.commit()
        if i == INITIAL_SIZE:
            print("Deletion of intermediate table from 0 to " + str(INITIAL_SIZE) + ". Done")
        else:
            print("Deletion of intermediate table from " + str(i - STEP + 1) + " to " + str(i) + ". Done")
        sleep(1)
        # Write package to inter_diet_table
        for index, row in package_df.iterrows():
            cursor.execute(
                'insert into inter_diet_table (id,fat,protein,carbs,calories,cost,temp_id) VALUES( %s, %s, %s, %s, %s, %s ,%s)',
                (str(row.id), str(row.fat), str(row.protein), str(row.carbs), str(row.calories), str(row.cost),
                 str(index1)))
            index1 += 1
        connection.commit()
        print("Writing Package to the next batch. Done")
        sleep(1)


def incremental_direct_testing():
    connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
    cursor = connection.cursor()
    data_size = pd.read_sql_query('select count(*) from "diet"', con=connection)
    index2 = 1
    for i in range(INITIAL_SIZE, int(data_size.values), STEP):

        if i == INITIAL_SIZE:
            print("Initial Phase Size: " + str(INITIAL_SIZE))
            inter_table = pd.read_sql_query(
                'select * from "diet" where id between (0) and (' + str(INITIAL_SIZE) + ')',
                con=connection)
            print("Insertion to intermediate table from 1 to " + str(INITIAL_SIZE) + ". Done")
        else:
            print("Incremental step")
            inter_table = pd.read_sql_query(
                'select * from "diet" where id between (0) and (' + str(i) + ')',
                con=connection)
            print("Insertion to intermediate table from 0 to " + str(i) + ". Done")
        inter_dataframe = pd.DataFrame(inter_table)
        # print(inter_dataframe)
        for index, row in inter_dataframe.iterrows():
            cursor.execute(
                'insert into inter_diet_table (id,fat,protein,carbs,calories,cost,temp_id) VALUES( %s, %s, %s, %s, %s, %s ,%s)',
                (str(row.id), str(row.fat), str(row.protein), str(row.carbs), str(row.calories), str(row.cost),
                 str(index2)))
            index2 += 1
        connection.commit()
        sleep(1)
        # Execute Package Builder
        os.chdir("/Users/vasilisvittis/PycharmProjects/Scalable-PaQL-Queries-master")
        os.system('bin/pb set cfg/example.cfg')
        print("Executing Package Builder, Method Direct. Done")
        sleep(3)

        # Delete all data with which you run Package Builder
        cursor.execute('delete from inter_diet_table')
        connection.commit()
        if i == INITIAL_SIZE:
            print("Deletion of intermediate table from 0 to " + str(INITIAL_SIZE) + ". Done")
        else:
            print("Deletion of intermediate table from 0 to " + str(i) + ". Done")
        sleep(1)


if __name__ == "__main__":
    incremental_packagebuilder_testing()
    # incremental_direct_testing()
