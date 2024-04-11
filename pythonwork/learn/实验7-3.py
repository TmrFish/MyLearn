import turtle
p = turtle.Turtle()
p.speed(5)
p.pensize(200)
p.pencolor("yellow")#画脸
p.circle(100,360)
p.penup()#画眼
p.seth(90)
p.fd(180)
p.seth(180)
p.fd(100)
p.seth(90)
p.pensize(60)
p.color("red")
p.pendown()
p.circle(20,180)#左心
p.circle(60,70)
p.left(38)
p.circle(60,70)
p.circle(20,180)
p.penup()
p.seth(0)
p.fd(200)
p.pendown()
p.seth(90)#右心
p.circle(20,180)
p.circle(60,70)
p.left(38)
p.circle(60,70)
p.circle(20,180)
p.penup()#转嘴
p.seth(180)
p.fd(100)
p.seth(270)
p.fd(180)
p.seth(180)
p.fd(95)
p.seth(270)
p.pendown()
p.pensize(10)
p.fillcolor(("red"))
p.begin_fill()
p.circle(95,180)
p.seth(180)
p.fd(190)
p.end_fill()
p.seth(0)#画牙
p.pencolor("white")
p.fd(190)





