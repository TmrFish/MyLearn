import math
print("请输入x=")
x=int(input())
y = math.sin(x) + 2 * math.sqrt(x + math.exp(4)) - math.pow(x + 1,3)\
        if((x>=0))else(math.log(-5 * x) - math.fabs(x * x - 8 * x)/(7 * x) + math.e)
print(y)