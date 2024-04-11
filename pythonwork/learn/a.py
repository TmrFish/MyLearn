for _ in range(100000):
    a,b = random.sample(range(1,10**5),2)
    if math.gcd(a,b) != gcd(a,b):
        print(a,b)