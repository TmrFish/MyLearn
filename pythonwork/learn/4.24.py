import sys
def gcd(p,q):
    if q == 0:return p
    return gcd(q,p % q)
p = int(sys.argv[1])
q = int(sys.argv[2])
print(gcd(p,q))