#陈艺铭
import time
import sys

# 定义函数Ackerman
def Ackerman(n, m):
    if n == 1 and m == 0:
        return 2
    if n == 0 and m >= 0:
        return 1
    if n >= 2 and m == 0:
        return n + 2
    if n >= 1 and m >= 1:
        return Ackerman(Ackerman(n-1, m), m-1)

inputs = [(2, 2), (3, 3), (4, 3), (5, 3)]

#计算内存
def memory_test(n, m):
    result = Ackerman(n, m)
    memory_size = sys.getsizeof(result)
    print(f" 占用内存大小：{memory_size} bytes")

#计算运行时间和内存
for n, m in inputs:
    start_time = time.time()
    result = Ackerman(n, m)
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Ackerman({n}, {m}) = {result}, 执行时间：{execution_time}秒")
    memory_test(n, m)


#空间复杂度为O(2^n)，时间复杂度为O(2^n)