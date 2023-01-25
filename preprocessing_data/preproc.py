import psycopg2
import pandas as pd


def load_data():
    connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
    cursor = connection.cursor()
    # cursor.execute('create table if not exists ' + "diet_dataset" + ' as select c1,c4,c5,c6,c7,c24,c170 from new_diet')
    # cursor.execute('ALTER TABLE "diet_dataset" ADD PRIMARY KEY (c1);')
    # connection.commit()


    dataset = pd.read_sql_query('select * from diet_dataset where weight IS NULL', con=connection)

    df = pd.DataFrame(dataset)
    print(df)
    # print(len(df.index))
    # df = df.dropna(how='any', axis=0)
    # print(len(df.index))
    # # nation and region => nation_region
    # #
    # # cursor.execute('drop table nation_region_customer_supplier')
    # # connection.commit()

if __name__ == "__main__":
    load_data()
