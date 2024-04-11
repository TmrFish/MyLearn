def swap2(s,i,j):
    s[i],s[j], = s[j],s[i]
s = [1,2]
swap2(s,0,1)
print(s)