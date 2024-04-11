for i in range(1,10):
    s = ""
    for t in range(1,i):
        print(end="      ")
    for j in range(i,10):
       s += str.format("{0:1}*{1:1}={2:<2}",i,j,i*j)
    print(s)
