import time
scale = 100
start = time.perf_counter()
for i in range(scale+1):
    a = '.' * i
    b = ' ' * (scale-i)
    c = (i/scale)*100
    d = time.perf_counter() - start
    print("\rstart[{}{}]{:^2.0f}% {:.2f}s".format(a,b,c,d),end='')
    time.sleep(0.5)
