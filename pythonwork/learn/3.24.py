EPSILON = 1e - 15
a = float(input("请输入正实数a:"))
t = a
while abs(t - a/t)>(EPSILON * t):
    t = (a/t + t)/ 2.0
print(t)