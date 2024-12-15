def Average(marks, n):
    total = 0
    for i in range(n):
        total += marks[i]
    average = total / n
    return average

def Maximum(marks, n):
    max_marks = marks[0]
    for i in range(1, n):
        if marks[i] > max_marks:
            max_marks = marks[i]
    return max_marks

def Minimum(marks, n):
    min_marks = 999
    for i in range(n):
        if marks[i] < min_marks and marks[i] >= 0:
            min_marks = marks[i]
    return min_marks

def Absent(marks, n):
    cnt = 0
    for i in range(n):
        if marks[i] == -1:
            cnt += 1
    return cnt

def Cntmax(marks, n, s):
    cntmax = 0
    for i in range(n):
        if marks[i] == s:
            cntmax += 1
    return cntmax

marks = []
n = int(input("Enter number of students, if absent please enter -1: "))
for i in range(n):
    m = int(input("Enter your marks: "))
    marks.append(m)

while True:
    print("Please press '1' for average")
    print("'2' for maximum marks")
    print("'3' for minimum marks")
    print("'4' for absent students")
    print("'5' for number of students with maximum marks")
    print("'6' for none")

    opt = int(input("Enter your choice: "))

    if opt == 1:
        avg = Average(marks, n)
        print("Average is:", avg)
    elif opt == 2:
        max_marks = Maximum(marks, n)
        print("Maximum marks:", max_marks)
    elif opt == 3:
        min_marks = Minimum(marks, n)
        print("Minimum marks:", min_marks)
    elif opt == 4:
        cnt = Absent(marks, n)
        print("No. of absent students:", cnt)
    elif opt == 5:
        max_marks = Maximum(marks, n)
        cntmax = Cntmax(marks, n, max_marks)
        print("The number of students having maximum marks:", cntmax)
    elif opt == 6:
        print("This option indicates you have chosen none!")
        break
    else:
        print("Invalid option, please try again.")


---
