def jiami(m,k):
    global an
    for i in m:
        if 'a'<=i<='z':
            an += chr(ord('a') + ((ord(i) - ord('a')) + int(k)) % 26)
        elif 'A'<=i<='Z':
            an += chr(ord('A') + ((ord(i) - ord('A')) + int(k)) % 26)
        else:
            an += i
    return an

def jiemi(a,k):
    ming2 = ''
    for i in a:
        if 'a'<=i<='z':
            ming2 += chr(ord('z') - ((ord('z') - ord(i)) + int(k)) % 26)
        elif 'A'<=i<='Z':
            ming2 += chr(ord('Z') - ((ord('Z') - ord(i)) + int(k)) % 26)
        else:
            ming2 += i
    return ming2



ming = input("请输入明文：")
k = input("请输入密钥:")
an = ''
print(jiami(ming,k))
print(jiemi(an,k))