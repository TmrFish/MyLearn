pi = 3.141592653589793
e = 2.718281828459045
def my_func():
    global pi
    pi = 3.14
    print('global pi =',pi)
    e = 2.718
    print('local e =',e)
print('module pi = ',pi)
print('module e = ',e)
my_func()
print('module pi = ',pi)
print('module e = ',e)