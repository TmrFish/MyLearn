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

# *---------获取天气内容--------*
def getweather(bs):
    sall = bs.select('ul[class="t clearfix"]')[0]
    day = sall.find_all('h1')
    weather_predict = sall.select('p[title]')
    tem = sall.find_all('p', {"class": "tem"})
    wind = sall.find_all('p', {"class": "win"})
    for i in range(7):
        print("{0}  {1}  {2}  {3}  {4}".format(day[i].get_text(), weather_predict[i].get_text(),
                                               tem[i].get_text().replace("\n", "")
                                               , wind[i].select('span')[0].get('title'),
                                               wind[i].select('i')[0].get_text().replace("\n", "")))

# *---------获取天气内容--------*


def main():
    bs = gethtml('http://www.weather.com.cn/weather/101280101.shtml')
    print("今日以及未来几天天气为：")
    getweather(bs)
    x = input("输入a结束")
    if x==a:
        return


if __name__ == '__main__': main()