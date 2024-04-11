
import jieba
def cutA():
    # 定义自定义词典内容
    custom_dict = ["南京市", "南京市长", "长江大桥", "大桥"]

    # 加载自定义词典（一次性添加多个词）
    for word in custom_dict:
        jieba.add_word(word)

    # 待分词的文本
    text = "南京市长江大桥"
  
    # 使用jieba分词
    words = list(jieba.cut(text))

    # 输出分词结果
    print(" / ".join(words))



# 按装订区域中的绿色按钮以运行脚本。
if __name__ == '__main__':
    cutA()

# 访问 https://www.jetbrains.com/help/pycharm/ 获取 PyCharm 帮助
