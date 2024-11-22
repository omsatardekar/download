import math

def karatsuba(x, y):
    if x < 10 and y < 10:
        return x*y

    n=max(len(str(x)) , len(str(y)))
    m= int(math.ceil(float(n)/2))

    x_H = int(math.floor(x / 10**m))
    x_L = int(x % (10**m))

    y_H = int(math.floor(y / 10**m))
    y_L = int(y % (10**m))

    S1= karatsuba(x_H, y_H)
    S2= karatsuba(x_L, y_L)
    S3= karatsuba(x_H + x_L , y_H + y_L)
    S4= S3-S2-S1

    return int(S1*(10**(m*2)) + S4*(10**m)+ S2)

a= int(input("Enter first no: "))
b= int(input("Enter second no: "))

print("result = " , karatsuba(a,b))
