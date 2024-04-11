while True:
    p = int(input("请输入评委人数:"))
    if p<2:
        print("输入的评委数需要>2")
        continue
    else:
        break

s = []
for i in range(1,p+1):
    f = int(input("请输入第{}个评委的分数:".format(i)))
    if (f<0 or f>100):
        print("分数需要大于0小于100")
        continue
    s.append(f)
ns = sorted(s)
ns = ns[1:-1]
average = sum(ns)/len(ns)
print("该选手最后的得分是：{:.1f}".format(average))



