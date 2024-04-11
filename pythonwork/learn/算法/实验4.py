'''
name：谭铭瑞
内容： 最大子段问题
'''
import time
import random

def maxSubsegmentSum2(nums):
    # 暴力求解
    sum = 0
    for i in range(1,len(nums)):
        for j in range(i,len(nums)):
            thissum = 0
            for k in range(i,j):
                thissum += nums[k]
            if (thissum > sum):
                sum = thissum
    return sum

def maxSubsegmentSum(nums):
    #动态规划
    #讲问题分解为以a[i]结尾的最大子段和
    #求解下一个以a[i+1]结尾的最大子段和时，可用上一个问题的解加上a[i+1]为当前问题的解，如果上一个大于零就加，小于零就不加，因为只会让当前问题的子段和变小
    sum = 0 #最大子段和
    b = 0   #保存的最大子段和
    for i in range(len(nums)):
        if(b>0):
            b+=nums[i]#如果上一个保存的最大子段和大于零则加入
        else:
            b = nums[i]#小于零则不加入，并以当前a[i]为新子段
        if(b >sum):
            sum = b#如果保存的最大子段和比之前保存的最大子段和打就更新
    return sum
# 测试
# 生成包含正负数的随机数组
random.seed(1)#固定随机数种子方便调试代码
n = 10**3
nums  = [random.randint(-100, 100) for _ in range(n)]

print(nums)
#暴力求解
start_time = time.perf_counter()
print(maxSubsegmentSum2(nums))
end_time = time.perf_counter()
execution_time2 = end_time - start_time
print(f"执行时间：{execution_time2}秒")
#动态规划
start_time = time.perf_counter()
print(maxSubsegmentSum(nums))
end_time = time.perf_counter()
execution_time = end_time - start_time
print(f"执行时间：{execution_time}秒")

print(f"时间差距：{execution_time2-execution_time}")
