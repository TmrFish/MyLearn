def gcd(m,n):
    if(m<n):
        m,n = n,m
    while (n!= 0):
        remainder = m % n
        m = n
        n = remainder
    return m
if __name__ == '__main__':
    print(24,36,"的最大公约数为:",gcd(24,36))