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

def main():
    bs = gethtml('http://www.weather.com.cn/weather/101280101.shtml')

    x = input("输入a结束")
    if x==a:
        return


if __name__ == '__main__': main()