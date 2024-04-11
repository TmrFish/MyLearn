# -*- coding: utf-8 -*-
import numpy as np
from sklearn import linear_model
# 随机生成X和Y
np.random.seed(0)
X = np.random.rand(100, 3)  # 生成100行3列的随机矩阵作为特征矩阵X
Y = 3 + np.dot(X, [4, 5, 6])  # 生成与X对应的Y，其中[4, 5, 6]为真实的参数

#拟合线性模型
reg = linear_model.LinearRegression()
reg.fit(X, Y)
print("调用库计算的解:",reg.intercept_,reg.coef_)
# 添加偏置项
X = np.c_[np.ones((X.shape[0], 1)), X]

# 求闭式解
theta = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(Y)
# 1.  `X.T`：表示矩阵X的转置。这里X是一个包含特征值的矩阵，每行是一个样本的特征向量。转置操作将每个特征向量转为每列一个特征值的矩阵。
#
# 2.  `X.T.dot(X)`：计算矩阵X的转置乘以矩阵X的结果。这是计算矩阵的点积（dot  product），也就是将矩阵X的列向量与转置后的X的行向量进行乘积运算，得到一个与样本特征数相等的方阵。
#
# 3.  `np.linalg.inv(X.T.dot(X))`：计算矩阵X的转置乘以X的结果的逆矩阵。这是通过`np.linalg.inv()`函数进行求逆操作。逆矩阵是对于矩阵X的转置乘以X的结果，可以用于回归模型参数的求解。
#
# 4.  `X.T.dot(X).dot(Y)`：计算矩阵X的转置乘以X的结果与向量Y的乘积。这是将矩阵X的列向量与转置后的X的行向量进行乘积运算，并与向量Y进行乘积运算，得到一个与样本特征数相等的列向量。
#
# 5.  `np.linalg.inv(X.T.dot(X)).dot(X.T).dot(Y)`：将上述的结果向量与矩阵X的转置的乘积再与向量Y的乘积相乘。这是进行参数theta的计算步骤，结果是一个包含回归模型参数theta的列向量。

# 打印参数
print("参数theta：", theta)


