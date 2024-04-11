while True:
    import math
    import random
    a,b=map(int,input("输入两个数字:").split(','))
    def gcd(a,b):
        factor = 1

        while a%2==0 and b%2==0:
            factor = factor*2
            a = a//2
            b = b//2

        while True:
            r = abs(a-b)
            if r == min(a,b):
                return r*factor
            else:
                a,b = b,r
    if __name__ == '__main__':
        print('{}和{}最大公约数为:'.format(a,b),gcd(a,b))