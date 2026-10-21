def sum_of_list(x: list):
    sum = 0

    for i in x:
        sum += i

    return sum

input_list = [10,20,30,40]
res_sum = sum_of_list(input_list)

print(res_sum)