

def calcualate_average(grades: list):

    total_items = len(grades)
    total_sum = 0

    for grade in grades:
        total_sum += grade

    return total_sum / total_items

def is_passed(avg):
    return avg >= 91


grades = [80, 70, 65, 35, 50]

average = calcualate_average(grades)
status = is_passed(average)

print(f'Average: {average}')
print(f'Status: {status}')

'''
data = {
'name': '',
cart_items : {
    [], ''
}
}
'''
