from bs4 import BeautifulSoup
from urllib.request import urlopen

# *---------获取url内容--------*
def gethtml(url):
    try:
        html = urlopen(url)
    except HTTPError as e:
        return None
    try:
        bs = BeautifulSoup(html.read(), 'html.parser')
    except AttributeError as e:
        return None
    else:
        return bs

# *---------获取url内容--------*

def new(main):
    print("学校新闻")
    ml = main.select('a[href^="http"]')
    for i in ml:
        print("链接文本：{};\n超链接：{}\n".format(i.get_text(), i.get('href')))




def gonggao(main,url):
    print("通知公告")
    mr = main.select('a[href^="/"]')
    for i in mr:
        print("链接文本：{};\n超链接：{}\n".format(i.get_text(), url + i.get('href')))


def pict(main,url):
    print("新闻图片")
    pictures = main.find_all('img')
    for i in pictures:
        print("新闻图片链接：", url + i.get('src'))


def main():
    url = 'https://www.gdufe.edu.cn'
    bs = gethtml(url)
    main = bs.select('div[class="wrapper main1"]')[0]
    new(main)
    gonggao(main,url)
    pict(main,url)



    x = input("输入a结束")
    if x==a:
        return


if __name__ == '__main__': main()