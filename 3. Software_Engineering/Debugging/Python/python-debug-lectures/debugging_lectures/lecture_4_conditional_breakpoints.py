def square_list(numbers: list):

    for number in numbers:
        res = number ** 2

        print(f'Square of {number} is - {res}')

numbers = {1, 2, 3, 4, 5, 6, 7, 8}
square_list(numbers)