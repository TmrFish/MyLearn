#姓名：谭铭瑞
#爬楼梯
def plt_method(n):
    n = int(n)
    if n == 1:
        return 1
    if n == 2:
        return 2
    return plt_method(n - 1) + plt_method(n - 2)

n=input("输入楼梯阶数：")
print("该上楼方法有：",plt_method(n))

