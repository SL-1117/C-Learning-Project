
'''
The program is supposed to calcualte the average marks of a student and say whether
the student is pass or fail. Average greater than or equal to 40 is pass.
'''

def calculate_average(marks):
    total = 0
    for mark in marks:
        total += mark
    return total // len(marks) 

def is_passed(avg):
    return avg >= 40 

marks = [40, 40, 40, 40, 40] 

average = calculate_average(marks)
status = is_passed(average)

print("Average:", average)
print("Result:", "Passed" if status else "Failed")