import os
import jieba
import codecs
from gensim import corpora
from gensim.models import LdaModel
from gensim import models
import matplotlib.pyplot as plt
import numpy as np
# 获取当前目录
current_dir = os.getcwd()
output_file_path = os.path.join(current_dir, 'output.txt')
if os.path.exists(output_file_path):
    with open(output_file_path, 'w', encoding='utf-8'):
        pass  # 创建或清空文件
else:
    open(output_file_path, 'w', encoding='utf-8').close()  # 创建新文件
# 指定输入文件路径
files_to_clean = [
    os.path.join(current_dir, '新浪新闻', 'test1.txt'),
    os.path.join(current_dir, '新浪新闻', 'test2.txt'),
    os.path.join(current_dir, '新浪新闻', 'test3.txt'),
]

# 加载停用词
stopwords_path = os.path.join(current_dir, 'hit_stopwords.txt')
with open(stopwords_path, 'r', encoding='utf-8') as f:
    stop_words = [line.strip() for line in f.readlines()]


def dataclean(file_path):
    # 读取文本文件内容
    with open(file_path, 'r', encoding='utf-8') as file:
        text = file.read()

    # 定义一个包含常见中文标点的集合
    chinese_punctuation = set('，、。！？；：“”‘’《》【】「」『』…—·～')

    # 删除标点符号
    text_without_punctuation = ''.join(c for c in text if c not in chinese_punctuation)

    # 对文本进行分词
    words = jieba.lcut(text_without_punctuation)

    # 删除停用词
    filtered_words = [word for word in words if word not in stop_words]
    # 移除空格，并将换行符视为分隔符进行处理
    filtered_words_no_space_and_newline = [word for word in filtered_words if word.strip()]
    # 将分词结果以逗号分隔的形式写入到新的txt文件中，每个文档结果占一行
    with open(output_file_path, 'a', encoding='utf-8') as output_file:
        output_file.write(','.join(filtered_words_no_space_and_newline) + '\n')  # 添加换行符

    print(f"文档 '{os.path.basename(file_path)}' 的分词结果已保存至 '{output_file_path}' 文件中。")


# 清洗所有指定的文档
for file in files_to_clean:
    dataclean(file)


te = []
with open(output_file_path, 'r',encoding='utf-8') as fp:
    for line in fp:
        line=line.split(',')
        te.append([w for w in line ])
print('输人文本数量:',len(te))
dictionary=corpora.Dictionary(te)
corpus=[dictionary.doc2bow(text) for text in te]
tfidf = models.TfidfModel(corpus)
corpus_tfidf = tfidf[corpus]
# print(list(corpus_tfidf))
# print (list(corpus))
lda=LdaModel(corpus=corpus,id2word=dictionary,num_topics=6,passes=100,random_state=42)
doc_topic=[a for a in lda[corpus]]
topics_r = lda.print_topics(num_topics=6, num_words=10)
topic_name=codecs.open('topies_result3.txt','w')
for v in topics_r:
    topic_name.write(str(v)+'\n')
fp2=codecs.open('documents_result.txt','w')
for t in doc_topic:
    c = []
    c.append([a[1] for a in t])
    print(t)
    m =max(c[0])
    for i in range(0,len(t)):
        if m in t[i]:
            fp2.write(str(t[i][0]) + ' ' + str(t[i][1]) + '\n')
            break