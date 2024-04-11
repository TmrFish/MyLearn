from bs4 import BeautifulSoup
import requests
from urllib.request import urlopen

# *-------------反反爬--------*

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36 Edg/108.0.1462.42",
           "Cookie":"ddscreen=2; __permanent_id=20221209153410146419057396291773630; dest_area=country_id%3D9000%26province_id%3D111%26city_id%3D0%26district_id%3D0%26town_id%3D0; __visit_id=20221209234746737139522637797888807; __out_refer=; __rpm=s_112100...1670602306160%7Clogin_page...1670602310675; login.dangdang.com=.AYH=&.ASPXAUTH=DqH8QtCgJ33HmBD3BP29g1l4mm3/oi2cZDujbiw33po5lpigcXIUQg==; dangdang.com=email=NTI0YzY2YTViNjhkYTk0N0BkZG1vYmlsZV91c2VyLmNvbQ==&nickname=tMqyu7Tv0uIu&display_id=5529400927094&customerid=qZ91KRWGHIsf/UkC7/gfPQ==&viptype=&show_name=136%2A%2A%2A%2A4890; ddoy=email=524c66a5b68da947%40ddmobile_user.com&nickname=%B4%CA%B2%BB%B4%EF%D2%E2.&validatedflag=0&agree_date=1; sessionID=pc_204dd66ffdb7e8ee33abdffc21de162ccb92101dd1300870d96d0db36fe08979; bind_cust_third_id=ocil5uOkNnuKibKqtqsnlX871goE; bind_custid=628125220; tx_open_id=oqh4kuATT5zpc6GtMJC8JkAcCb-8; tx_nickname=tMqyu7Tv0uIu; tx_figureurl=https://thirdwx.qlogo.cn/mmopen/vi_32/pINhB4r7SZeibTIYIkw4H4lgwsq0icRvnbmVzlWqOhSbhTemRtE0aLBS2ia82n1ibrKoBMicU2GXwmorm62qqJox4xA/132; order_follow_source=-%7C-O-123%7C%2311%7C%23login_third_weixin%7C%230%7C%23; LOGIN_TIME=1670602992417; search_passback=0bc9469a676a22a3126393630c000000e24f670009639363; __trace_id=20221210003219387190661480037574531; pos_9_end=1670603539583; ad_ids=3554365%2C2723462%2C2095975%2C2531198%7C%233%2C3%2C3%2C2; pos_0_start=1670603539891; pos_0_end=1670603539898",
           "Accept-Language":"zh-CN,zh;q=0.9",
           "Accept-Ranges":"bytes",
           "Referer":"https://search.dangdang.com/?key=%E7%BA%A2%E6%A5%BC%E6%A2%A6"
           }
# *-------------定义Content--------*
class Content:
    def __init__(self,topic,url,title,body):
        self.topic = topic
        self.title = title
        self.body = body
        self.url = url


    def print(self):
        print("搜索:{}".format(self.topic))
        print("书名:{}".format(self.title))
        print("价格:{}".format(self.body))
        print("购买网址:{}".format(self.url))

# *-------------定义Website--------*
class Website:
    def __init__(self,name,url,searchUrl,resultListing,
                 resultUrl,absoluteUrl,titleTag,bodyTag):
        self.name = name
        self.url = url
        self.searchUrl = searchUrl
        self.resultListing = resultListing
        self.resultUrl = resultUrl
        self.absoluteUrl = absoluteUrl
        self.titleTag = titleTag
        self.bodyTag = bodyTag

# *--------------定义Crawler-----------------*
class Crawler:
    def getPage(self,url):
            html = requests.get(url,headers=headers)
            bs = BeautifulSoup(html.text, 'html.parser')
            return bs

    def safeGet(self,pageObj,selector):
        childObj = pageObj.select(selector)
        if childObj is not None and len(childObj) > 0:
            return childObj[0].get_text()
        return ''

    def search(self,topic,site):
        bs = self.getPage(site.searchUrl + topic)
        searchResults = bs.select(site.resultListing)
        for result in searchResults:
            url = result.select(site.resultUrl)[0].attrs["href"]
            if(site.absoluteUrl):
                bs = self.getPage(url)
            else:
                a = 'https:'+ url
                bs = self.getPage(a)
            if bs is None:
                print("发生了错误，跳过")
                return
            title = self.safeGet(bs,site.titleTag)
            body = self.safeGet(bs, site.bodyTag)
            if title != '' and body != '':
                content = Content(topic,a,title,body)
                content.print()


    def parse(self,site,url):
        bs = self.getPage(url)
        if bs is not None:
            title = self.safeGet(bs,site.titleTag)
            body = self.safeGet(bs, site.bodyTag)
            if title != '' and body != '':
                content = Content(url,title,body)
                content.print()


# *--------------主函数-----------------*
def main():
    crawler = Crawler()

    # 'name','url','searchUrl','resultListing','resultUrl','absoluteUrl','titleTag','bodyTag'
    siteData = [
        ['0\'当当网','https://search.dangdang.com','https://search.dangdang.com/?key='
            ,'#component_59 > li','p.name > a',
         False,'div.name_info > h1','#dd-price']
    ]

    sites = []
    for row in siteData:
        sites.append(Website(row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7]))

    topics = ['屁屁侦探系列']
    for topic in topics:
        print("正在搜索:"+ topic)
        for targetSite in sites:
            crawler.search(topic,targetSite)





if __name__ == '__main__': main()