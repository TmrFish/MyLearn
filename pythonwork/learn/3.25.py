f1 = 1;f2 = 1
for i in range(1,11):
    print(str.format("{0:6}{1:6}",f1,f2),end=" ")
    
    if i % 2 ==0:print()
    f1 += f2;f2 += f1