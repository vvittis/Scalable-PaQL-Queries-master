import os
import matplotlib.pyplot as plt
from testing.Parser import parser, parser_metrics
import pandas as pd
import psycopg2

NUMBER_OF_TESTS = 4


def plot(experiment_name, initial_size, dataset_size, batch_size, y_direct, y_package, y_direct_error, y_package_error, query_ids ):
    # fig = plt.figure()
    fig, axes = plt.subplots(1, NUMBER_OF_TESTS, figsize=(20, 5))
    fig.suptitle('Comparison between Naive Direct, Greedy IPM ', fontname="serif", size=20, fontweight="bold")
    index = 0
    i = 0
    for ax in axes:
        x = []
        for value in range(initial_size, dataset_size + 1, batch_size):
            x.append(value)
        plt.rc('font', family='serif')
        range_size = round(dataset_size - initial_size, -2)
        parts = round(range_size / 4, -2)
        checkpoint1 = initial_size + 1 * parts
        checkpoint2 = initial_size + 2 * parts
        checkpoint3 = initial_size + 3 * parts

        ax.errorbar(x, y_direct[i], yerr=y_direct_error[i], markersize=4, fmt='o', ls='dotted', color='red', capsize=5)
        ax.errorbar(x, y_package[i], yerr=y_package_error[i], markersize=5, fmt='x', ls='dotted', color='blue',capsize=5)
        # ax.errorbar(x, y_acc[i], yerr=y_acc_error[i], markersize=4, fmt='o', ls='dotted', color='green',
        #             capsize=5)
        ax.set_xticks([initial_size, checkpoint1, checkpoint2, checkpoint3, dataset_size])
        # temp_y_package = y_package[i]
        # temp_y_direct = y_direct[i]
        # temp_y_package_error = y_package_error[i]
        # temp_y_direct_error = y_direct_error[i]
        # for idx, txt in enumerate(y_number_package[i]):
        #     ax.annotate(txt, (x[idx], (temp_y_package[idx] + temp_y_package_error[idx])), color='blue')
        # for idx1, txt1 in enumerate(y_number_direct[i]):
        #     ax.annotate(txt1, (x[idx1], (temp_y_direct[idx1] + temp_y_direct_error[idx1])), color='red')
        ax.set_xticklabels([str(initial_size / 10) + "%", str(checkpoint1 / 10) + "%", str(checkpoint2 / 10) + "%", str(checkpoint3 / 10) + "%", '100%'])
        ax.tick_params(axis="x", direction="in")
        ax.tick_params(axis="y", direction="in")
        ax.grid(axis="x", alpha=1, linestyle=":")
        ax.set_title(str(query_ids[index]), fontname="serif", size=20, fontweight="bold")
        index += 1
        ax.set_ylabel('Value of Objective Function')
        ax.set_xlabel('Dataset Size')
        # ax.legend()
        plt.tight_layout()
        import tikzplotlib
        # out_file_name = 'figures/tex/testing_figure.tex'
        # tikzplotlib.save(out_file_name, axis_height='15cm', axis_width='15cm', strict=True)
        i += 1
    fig.legend(["Direct", "Greedy IPM"], loc='center right')
    # hL.Layout.Tile = 'East';
    plt.savefig('figures/plots/asd.pdf', bbox_inches='tight')
    # plt.savefig('testing/figures/plots/' + experiment_name + '_no_infe_see_what_happens' + str(initial_size) + '_' + str(batch_size) + '.pdf',bbox_inches='tight')
    plt.show()


def setup_plot(experiment_dataframe):
    connection = psycopg2.connect(host="localhost", port="5432", database="Diet", user="postgres")
    cursor = connection.cursor()

    query_names = []
    temp_objective_value_ipm = []
    temp_error_ipm = []
    temp_objective_value_direct = []
    temp_error_direct = []

    experiment_name = ''
    initial_size = None
    dataset_size = None
    batch_size = None

    for index, row in experiment_dataframe.iterrows():
        experiment_name = row.exp_name
        initial_size = row.initial_size
        batch_size = row.step
        query_names.append(row.query_name)
        # (obj, row.id, row.exp_name, row.query_file, row.initial_size, row.step)
        table_name = "results_exp_id_" + str(row.id)
        dataset_size = int(pd.read_sql_query('SELECT max(iteration) FROM ' + table_name + ' where function = \'IPM\'', con=connection).values)
        target_view_table = 'plotting_' + table_name + '_metrics'
        cursor.execute(
            'CREATE VIEW ' + target_view_table + ' AS SELECT function, iteration,avg(obj_value) as obj_value, stddev(obj_value) as error from ' + table_name + ' GROUP BY iteration, function ORDER BY function, iteration ')
        connection.commit()
        dataset_ipm = pd.read_sql_query('select obj_value, error from ' + target_view_table + ' where function = \'IPM\'', con=connection)
        df_ipm = pd.DataFrame(dataset_ipm)
        temp_objective_value_ipm.append(df_ipm.obj_value.to_numpy().flatten())
        temp_error_ipm.append(df_ipm.error.to_numpy().flatten())
        dataset_direct = pd.read_sql_query('select obj_value, error from ' + target_view_table + ' where function = \'DIRECT\'', con=connection)
        df_direct = pd.DataFrame(dataset_direct)
        temp_objective_value_direct.append(df_direct.obj_value.to_numpy().flatten())
        temp_error_direct.append(df_direct.error.to_numpy().flatten())
        cursor.execute('DROP VIEW ' + target_view_table)
        connection.commit()
    plot(experiment_name=experiment_name, initial_size=initial_size, dataset_size=dataset_size, batch_size=batch_size, y_direct=temp_objective_value_direct,
         y_direct_error=temp_error_direct, y_package=temp_objective_value_ipm, y_package_error=temp_error_ipm, query_ids=query_names)


if __name__ == "__main__":
    setup_plot()
