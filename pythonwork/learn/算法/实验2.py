'''
name: 谭铭瑞
time:2023/10/20
'''
################################## 问题一
# import random
# import sys
# import time
#
# def separate_digits(num):
#     if num < 0:
#         num = -num
#
#     if num == 0:
#         print(0)
#     else:
#         digits = []
#         while num > 0:
#             digit = num % 10
#             digits.append(digit)
#             num = num // 10
#         digits.reverse()
#         print(digits)
#
# # 生成随机整数n
# n_decimal = random.randint(-2**31, 2**31)
#
#
# print("随机的十进制整数：", n_decimal)
# print("各位数分离：")
# start_time1 = time.time()
# print("十进制位数分离实际占用空间：", sys.getsizeof(separate_digits(n_decimal)), "字节")
# end_time1 = time.time()
# print("十进制位数分离实际执行时间：", (end_time1 - start_time1))

################################## 问题二
#
# import time
# #递归用法
# def feibo(n):#菲波那契数递归计算
#     if n == 0:
#         return 1
#     if n == 1:
#         return 1
#     if n > 1:
#         return feibo(n-1) + feibo(n-2)
#
# def sumfeibo(n):#累加
#     sum = 0
#     time.sleep(1)
#     for i in range(1,n+1):
#         sum += feibo(i)
#         if sum >= 100:
#             return i-1,sum-feibo(i)
#     return n,sum
#
# start_time1 = time.time()
# maxn , sum = sumfeibo(100)#最大n值以及对应累加和
# end_time1 = time.time()
# print("递归方式：")
# print("F(1)+F(2)+……+F(", maxn, ") 小于 100 的最大n值为:", maxn)
# print("对应的累加和为:", sum)
# print("递归实际执行时间：", (end_time1 - start_time1 - 1 ))
#
#
# #非递归用法
# def feibo_nodigui():
#     time.sleep(1)
#     a, b = 1,2
#     total = 3  # F(1)和F(2)的累加和已知为2
#     n = 2
#     while total < 100:
#         a, b = b, a + b
#         total += b
#         n += 1
#     return n-1, total-b
#
# start_time1 = time.time()
# maxn2, sum2 = feibo_nodigui()
# end_time1 = time.time()
# print("非递归方式：")
# print("F(1)+F(2)+……+F(", maxn2, ") 小于 100 的最大n值为:", maxn2)
# print("对应的累加和为:", sum2)
# print("非递归实际执行时间：", (end_time1 - start_time1 - 1))



##################################问题三
def spiral_order(matrix):
    if not matrix:
        return []
    result = []
    m, n = len(matrix), len(matrix[0])
    top, bottom, left, right = 0, m-1, 0, n-1
    while top <= bottom and left <= right:
        for i in range(left, right+1):
            result.append(matrix[top][i])
        top += 1
        for i in range(top, bottom+1):
            result.append(matrix[i][right])
        right -= 1
        if top <= bottom:
            for i in range(right, left-1, -1):
                result.append(matrix[bottom][i])
            bottom -= 1
        if left <= right:
            for i in range(bottom, top-1, -1):
                result.append(matrix[i][left])
            left += 1
    return result

# 示例输入
matrix = [[1,2,3],[4,5,6],[7,8,9]]
# 调用函数，输出结果
print(spiral_order(matrix))

import random

def generate_random_matrix(m, n):
    return [[random.randint(1, 100) for _ in range(n)] for _ in range(m)]

# 生成随机 m 和 n
m, n = random.randint(1, 10), random.randint(1, 10)
print("生成的随机m和n为:", m, n)
# 生成随机 m*n 大小的矩阵
random_matrix = generate_random_matrix(m, n)
# 输出生成的随机矩阵
for row in random_matrix:
    print(row)
# 调用函数，输出结果
print(spiral_order(random_matrix))
