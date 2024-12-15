def Addition(r, c, m, m1):
    print("Addition of two matrices:")
    result = []
    for i in range(r):
        row = []
        for j in range(c):
            row.append(m[i][j] + m1[i][j])
        result.append(row)

    print("Using nested loops:")
    for row in result:
        print(row)

def Subtraction(r, c, m, m1):
    print("Subtraction of two matrices:")
    result = []
    for i in range(r):
        row = []
        for j in range(c):
            row.append(m[i][j] - m1[i][j])
        result.append(row)

    print("Using nested loops:")
    for row in result:
        print(row)

def Transpose(r, c, m):
    print("Transpose of the first matrix:")
    result = []
    for j in range(c):
        row = []
        for i in range(r):
            row.append(m[i][j])
        result.append(row)

    print("Using nested loops:")
    for row in result:
        print(row)

def Transpose1(r, c, m1):
    print("Transpose of the second matrix:")
    result = []
    for j in range(c):
        row = []
        for i in range(r):
            row.append(m1[i][j])
        result.append(row)

    print("Using nested loops:")
    for row in result:
        print(row)

def Multiplication(r, c, m, m1):
    print("Multiplication of matrices:")

    if r == c:
        result = []
        for i in range(r):
            row = []
            for j in range(c):
                sum = 0
                for k in range(c):
                    sum += m[i][k] * m1[k][j]
                row.append(sum)
            result.append(row)

        print("Using nested loops:")
        for row in result:
            print(row)
    else:
        print("Operation invalid: Matrices must be square i.e (n x n) for multiplication.")
m = []
r = int(input("Enter the number of rows: "))
c = int(input("Enter the number of columns: "))
for i in range(r):
    a = []
    for j in range(c):
        ele = int(input("Enter element: "))
        a.append(ele)
    m.append(a)

print("1st matrix is:")
for row in m:
    print(row)
m1 = []
for i in range(r):
    a = []
    for j in range(c):
        ele = int(input("Enter element: "))
        a.append(ele)
    m1.append(a)

print("2nd matrix is:")
for row in m1:
    print(row)
while True:
    print("Please press 1 for matrix addition;")
    print("Please press 2 for matrix subtraction;")
    print("Please press 3 for transpose of matrix 1;")
    print("Please press 4 for transpose of matrix 2;")
    print("Please press 5 for multiplication of matrices;")
    print("Please press 6 for none;")

    opt = int(input("Enter your choice: "))

    if opt == 1:
        Addition(r, c, m, m1)
    elif opt == 2:
        Subtraction(r, c, m, m1)
    elif opt == 3:
        Transpose(r, c, m)
    elif opt == 4:
        Transpose1(r, c, m1)
    elif opt == 5:
        Multiplication(r, c, m, m1)
    elif opt == 6:
        print("You opted for none!")
        break
    else:
        print("Invalid option, please try again.")