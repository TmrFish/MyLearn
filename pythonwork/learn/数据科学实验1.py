import re
import math

#计算TF数值的函数
def TF(i,Doc):
    global Doc1x    #利用global调用全局参数
    x = Doc1x
    a = len(Doc)
    b = len(re.findall(i,x))    #这里在第一次编写的时候x处用了元组而不是字符串，产生了错误，修正方式为，在前面调用全局参数
    c = b/a
    return c

#计算IDE数值的函数
def IDE(i,Doc):
    a = 0
    for x in Doc_list:
        if i in x:
            a += 1
    c = math.log10(len(Doc_list)/a)
    return c

#生成TF_IDF数值的函数，起到调用各函数的作用
def TF_IDF(i,Doc):
    a = TF(i,Doc)
    b = IDE(i,Doc)
    c = a * b
    return c

#总调用函数，用循环让四个文档分别调用TF_IDF函数
def TF_IDFFin(Doc):
    for i in Doc:
        print(i,":")
        print("TF*IDF=",TF_IDF(i,Doc))

#输入部分四个文档
Doc1x = "Olympic games end"
Doc2x = "football games begin"
Doc3x = "basketball games ongoing"
Doc4x = "volleyball games draw"

#将四个文档以空格划分，并形成元组
Doc1 = Doc1x.split()
Doc2 = Doc2x.split()
Doc3 = Doc3x.split()
Doc4 = Doc4x.split()

#输出格式和调用函数
Doc_list = [Doc1,Doc2,Doc3,Doc4]
Doc_con = len(Doc_list)
print("Doc1:------------")
TF_IDFFin(Doc1)
print("Doc2:------------")
TF_IDFFin(Doc2)
print("Doc3:------------")
TF_IDFFin(Doc3)
print("Doc4:------------")
TF_IDFFin(Doc4)


#Doc1x = input("请输入第一个文档")
#Doc2x = input("请输入第二个文档")
#Doc3x = input("请输入第三个文档")
#Doc4x = input("请输入第四个文档")
