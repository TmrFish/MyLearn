import turtle
p = turtle.Turtle()
p.speed(0)
colors = ["red","blue","green","yellow"]
for i in range(100):
    p.pencolor(colors[i%4])
    p.circle(i)
    p.left(91)