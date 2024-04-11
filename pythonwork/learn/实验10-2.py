def lou(n):#递归法
    if n == 1:return 1
    if n == 2:return 2
    if n == 3:return 4
    else:
        return lou(n-1) + lou(n-2) + lou(n-3)

def lou2(n):#递推法
    a = 1
    b = 2
    c = 4
    for i in range(n-3):
        t = c
        c = a + b + c
        a = b
        b = t
    return c


print(lou(int(input("递推请输入阶数"))))
print(lou2(int(input("递归请输入阶数"))))
