import random
def cai(m,n,d = 5):
    a = random.randint(m,n)
    for n in range(d):
        b = int(input('请猜猜这个数是多少：a = '))
        if b<a:
            print("猜小了")
            continue
        if b>a:
            print("猜大了")
            continue
        if b==a:
            print("恭喜你猜对了,第{}次猜对".format(n+1))
            return
    print("游戏结束，正确答案是:", a)


print("猜数游戏开始，请输入范围[m,n]")
cai(int(input("m=")),int(input("n=")))




