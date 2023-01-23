# the general form is
#
# value1 {comma} value2 {comma}..., value N | objective_function {comma} status

def parser(input_string):
    print("Parsing Data... ")

    elements = input_string.split("|")
    # status
    right_side = elements[1]
    objective_function, status, p_size = right_side.split(',')
    # print("Objective Function value: " + str(objective_function) + " and status: " + str(status))
    values = elements[0].split(',')
    val = []
    if values[0] is not '':
        for i in values:
            val.append(int(i))
    else:
        val.append(-1)
    print(val, objective_function)
    return val, objective_function, p_size


def parser_metrics(input_string):
    elements = input_string.split(",")
    objective_value = elements[0]
    std_error = elements[1]
    if len(elements) == 2:
        package_size = 0
    else:
        package_size = elements[2]
    return objective_value, std_error, package_size


if __name__ == "__main__":
    str = "|-1,fail"
    parser(str)
