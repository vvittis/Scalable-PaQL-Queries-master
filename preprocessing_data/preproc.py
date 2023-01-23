import psycopg2
import pandas as pd


def load_data():
    connection = psycopg2.connect(host="localhost", port="5432", database="TPC-H", user="postgres")
    cursor = connection.cursor()

    count_lines = pd.read_sql_query('select count(*) from lineitem', con=connection)
    print(count_lines)
    # nation and region => nation_region
    #
    # cursor.execute('drop table nation_region_customer_supplier')
    # connection.commit()

if __name__ == "__main__":
    load_data()
