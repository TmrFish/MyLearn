import random
def zhua(n,t = 10):
    a = random.randint(1,n)
    for n in range(t):
        b = int(input('请猜猜狐狸在哪个洞： '))
        if b<=0:
            print("请输入大于零的数")#输入的数小于零时退出
            return
        if b>n:
            print("请输入范围内的数")#输入的数处于范围外时退出
            return
        if b==a:
            print("恭喜你抓到了狐狸")
        else:
            print("没抓到！狐狸跑了")
            c = random.randint(0,1)#设定一个随机数，若为0去左边的坑，若为1去右边坑，嵌套结构，让狐狸在最左边的坑抽到0无法转左时向右转
            if c==0:
                if a==1:
                    a = a + 1
                else:
                    a = a - 1
            if c==1:
                if a==10:
                    a = a - 1
                else:
                    a = a + 1
        continue
    print("游戏结束，你没抓到狐狸:", a)

zhua(int(input("抓狐狸游戏开始，你想要狐狸有几个洞口:")))