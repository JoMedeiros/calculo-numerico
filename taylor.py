
import math

formula = "x "
sign = ['+','-']
for n in range(3,15,2):
    formula = formula +\
    sign[math.floor(n/2)%2] +\
    "(x**"+str(n)+")/"+\
    str(math.factorial(n-1))

print(formula,end="")
print("outra coisa",end="")
print("bye world",end="")
