# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
from sklearn import linear_model
import numpy as np

#训练数据
x=np.array([[1,0,180,165,175,165,170,165],
            [3,0,180,165,175,165,173,165],
            [4,0,180,165,175,165,170,165],
            [6,0,180,165,175,165,170,165],
            [8,1,180,165,175,167,170,165],
            [10,0,180,166,175,165,170,165],
            [11,0,180,165,175,165,170,165],
            [12,0,180,165,175,165,170,165],
            [13,1,180,165,175,165,170,165],
            [14,0,180,165,175,165,170,165],
            [17,0,170,165,175,165,170,165]])
#儿童身高
y=np.array([60,90,100,110,130,140,150,164,160,163,168])

#拟合线性模型
reg = linear_model.LinearRegression()
reg.fit(x, y)

#以下是待测的未知数据，其中每个分量的含义和训练数据相同
x_test=np.array([[10,0,180,165,175,165,170,165],
             [17,1,173,153,175,161,170,161],
             [34,0,170,165,170,165,170,165]])
y_test = reg.predict(x_test)
print("reg.score:{:.2f}".format(reg.score(x_test, y_test)))
