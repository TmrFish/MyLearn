'''
name: 施治强
time:2023/10/20
project:输入即可随机生成0<=x<=10^9数组,并对其排序(快速和冒泡)
'''
import random
import sys
import time


def get_shuzu(n):
    # 函数功能：获取n个随机数组
    shuzu = []
    for i in range(0, n):
        shuzu.append(random.randint(0, 10**9))
    return shuzu


def quick_sort(shuzu):
    # 函数功能：对数组内进行快速排序
    if len(shuzu) <= 1:
        # 结束的条件
        return shuzu
    line = shuzu[len(shuzu) // 2]   # 中间值为分界
    left = [x for x in shuzu if x < line]
    middle = [x for x in shuzu if x == line]
    right = [x for x in shuzu if x > line]
    return quick_sort(left) + quick_sort(middle) + quick_sort(right)


def bubble_sort(shuzu, n):
    # 函数功能：对数组内进行冒泡排序
    if n == 1:
        # 结束的条件
        return shuzu
    # 对前n - 1 个元素进行冒泡排序
    for i in range(n - 1):
        if shuzu[i] > shuzu[i + 1]:
            shuzu[i], shuzu[i + 1] = shuzu[i + 1], shuzu[i]
    return bubble_sort(shuzu, n - 1)


shuzu_5 = get_shuzu(5)
shuzu_10 = get_shuzu(10)
shuzu_100 = get_shuzu(100)


def test1():    # 测试快速排序法
    print("排序前:\n",
          shuzu_5, "\n",
          shuzu_10, "\n",
          shuzu_100)
    print("排序后:\n",
          quick_sort(shuzu_5), "\n",
          quick_sort(shuzu_10), "\n",
          quick_sort(shuzu_100))


def test2():    # 测试冒泡排序法
    print("排序前:\n",
          shuzu_5, "\n",
          shuzu_10, "\n",
          shuzu_100)
    print("排序后:\n",
          bubble_sort(shuzu_5, len(shuzu_5)), "\n",
          bubble_sort(shuzu_10, len(shuzu_10)), "\n",
          bubble_sort(shuzu_100, len(shuzu_100)))


start_time1 = time.time()
print("快速排序实际占用空间：", sys.getsizeof(test1()), "字节")
end_time1 = time.time()
print("快速排序实际执行时间：", (end_time1 - start_time1))


start_time2 = time.time()
print("冒泡排序实际占用空间：", sys.getsizeof(test2()), "字节")
end_time2 = time.time()
print("冒泡排序实际执行时间：", (end_time2 - start_time2))