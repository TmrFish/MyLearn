import sys
import turtle
def koch(t,order,size):
    if order == 0:
        t.forward(size)
        t.left(120.0)
        t.forward(size)
        t.left(120.0)
        t.forward(size)
        t.left(120.0)

    else:
        koch(t,order-1,size/2)
        t.forward(size)
        t.left(120.0)
        koch(t,order-1,size/2)
        t.forward(size)
        t.left(120.0)
        koch(t,order-1,size/2)
        t.forward(size)
        t.left(120.0)
def main():
    n = int(sys.argv[1])
    step = 300
    p = turtle.Turtle()
    koch(p,n,step)
if __name__ == '__main__':main()
input()
#python 实验10-3.py 3