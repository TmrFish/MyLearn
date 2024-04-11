from urllib.request import urlopen
from bs4 import BeautifulSoup


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


# *---------获取第一个P的兄弟节点--------*
def getPbrother(bs):
    print("一个P标签的兄弟节点是:")
    for sibling in bs.find('p').next_siblings:
        print(sibling)
    return


# *---------获取第一个P的兄弟节点--------*


# *---------获取第二个P的子节点--------*
def getPson(bs):
    print("第二个P标签的子节点是:")
    for child in bs.find('p', {'class': 'story'}):
        print(child)
    print("a标签的href属性内容")
    ass = bs.find('p', {'class': 'story'}).find_all('a')
    for a in ass :
        print(a['href'])


    return


# *---------获取第二个P的子节点--------*


def main():
    bs = gethtml('http://47.241.168.242/WebScraping/beautifulsoup.html')
    getPbrother(bs)
    getPson(bs)


if __name__ == '__main__': main()