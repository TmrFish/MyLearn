from bs4 import BeautifulSoup
from urllib.request import urlopen
import requests
import time

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



def main():
    url = 'https://www.gdufe.edu.cn'
    bs = gethtml(url)
    mains = bs.find('div', {'class': 'movies-list'})
    name = mains.select('span[class="name noscore"]')
    pict = mains.select('img[src^="https"]')
    linkers = mains.select('div[class="movie-item-hover"] a')
    url2 = "https://www.maoyan.com"
    for i in range(len(pict)):
        print("电影名称：{};  电影海报链接：{}\n 电影链接：{}\n".format(name[i].get_text(), pict[i].get('src'),
                                                       url2 + linkers[i].get('href')))
    input()
    x = input("输入a结束")
    if x==a:
        return


if __name__ == '__main__': main()