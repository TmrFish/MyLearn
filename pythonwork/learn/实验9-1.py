import string
def mima(a):
    shu = string.digits
    daxie = string.ascii_lowercase
    xiaoxie = string.ascii_uppercase
    fuhao = '@'';'',''!''?''<''>''.'
    h = 0
    j = 0
    k = 0
    l = 0
    if len(a)<6:
        print("密码字符个数必须大于等于6")
        return('')
    for i in a:
        if i in shu:
            h += 1
        elif i in daxie:
            j += 1
        elif i in xiaoxie:
            k += 1
        elif i in fuhao:
            l += 1
    h2=int(bool(h))
    j2=int(bool(j))
    k2=int(bool(k))
    l2=int(bool(l))
    sum = h2 + j2 + k2 + l2
    if sum == 0:
        return('错误的密码格式')
    elif sum == 1:
        return('该密码安全强度弱')
    elif sum == 2:
        return('该密码安全强度中低')
    elif sum == 3:
        return('该密码安全强度中高')
    elif sum == 4:
        return('该密码安全强度高')



s = input("请输入密码:")
print(mima(s))