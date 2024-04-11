def susu(a):
    if a==1:
        return 1
    for i in range(2,a):
        if a % i==0:
            return 1
        if i == (a-1):
            return 0

x = eval(input())
y = list(filter(susu,x))
print(y)