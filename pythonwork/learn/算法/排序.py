'''
name: 谭铭瑞
time:2023/10/30
project:随机生成0<=x<=10^9数组,并对其排序(快速和归并排序函数)
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

def merge_sort(arr):
    # 归并排序函数
    if len(arr) <= 1:
        return arr

    # 将数组分为两半并递归排序
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    # 合并排好序的子数组
    return merge(left, right)


def merge(left, right):
    # 合并两个有序数组
    merged = []
    i = j = 0

    # 比较左右两个数组的元素，按顺序合并
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    # 将剩余的元素添加到合并结果中
    merged.extend(left[i:])
    merged.extend(right[j:])

    return merged






def Ptest1(shuzu_5,shuzu_10,shuzu_100):    # 测试快速排序法
    print("排序前:\n",
          shuzu_5, "\n",
          shuzu_10, "\n",
          shuzu_100,"\n")
    print("排序后:\n",
          quick_sort(shuzu_5), "\n",
          quick_sort(shuzu_10), "\n",
          quick_sort(shuzu_100),"\n")

def Ptest2(shuzu_5,shuzu_10,shuzu_100):    # 测试归并排序法
    print("排序前:\n",
          shuzu_5, "\n",
          shuzu_10, "\n",
          shuzu_100,"\n")
    print("排序后:\n",
          merge_sort(shuzu_5), "\n",
          merge_sort(shuzu_10), "\n",
          merge_sort(shuzu_100),"\n")


def main():
    shuzu_5 = get_shuzu(5)
    shuzu_10 = get_shuzu(10)
    shuzu_100 = get_shuzu(100)

    start_time1 = time.time()
    print("快速排序实际占用空间：", sys.getsizeof(Ptest1(shuzu_5,shuzu_10,shuzu_100)), "字节")
    end_time1 = time.time()
    print("快速排序实际执行时间：", (end_time1 - start_time1))

    start_time2 = time.time()
    print("归并排序实际占用空间：", sys.getsizeof(Ptest2(shuzu_5,shuzu_10,shuzu_100)), "字节")
    end_time2 = time.time()
    print("归并排序实际执行时间：", (end_time2 - start_time2))

if __name__ == '__main__':
    main()


