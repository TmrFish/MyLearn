import random
def randomarray(n):
    a = []
    for i in range(n):
        a.append(random.random())
    return a
b = randomarray(5)
for i in b:print(i)