import re
def TF(i,Doc):
    print(type(Doc))
    a = len(Doc)
    b = len(re.findall(i,Doc))
    c = b/a
    print(b)

def TF_IDFFin(Doc):
    for i in Doc:
        print(i,":")
        TF(i, Doc)


Doc1x = "Olympic games end"
Doc1 = Doc1x.split()
TF_IDFFin(Doc1)