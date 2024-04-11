def outer_func():
    tax_rate = 0.17
    print('outer func tax rate =',tax_rate)
    def inner_func():
        nonlocal tax_rate
        tax_rate = 0.05
        print('inner func tax rate =',tax_rate)
    inner_func()
    print('outer func tax rate = ',tax_rate)
outer_func()