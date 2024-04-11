import os
import csv
# 定义文件夹路径
folder_path = 'G:/mod/testdata_V2/all/labels'
# 获取文件夹中所有文本文件的路径
file_paths = [os.path.join(folder_path, filename) for filename in os.listdir(folder_path) if filename.endswith('.txt')]
# 初始化结果列表
result = []
# 逐个读取文本文件的数据
for file_path in file_paths:
    # 打开文本文件
    with open(file_path, 'r') as file:
        # 读取文件内容
        content = file.read()
        # 假设normal和potholes的概率在两行文本中，通过换行符拆分文本
        lines = content.split('\n')
        xname = lines[0].split(' ')[1]
        if xname == 'normal':
            normal_probability = float(lines[0].split(' ')[0])
            potholes_probability = float(lines[1].split(' ')[0])
        else:
            potholes_probability = float(lines[0].split(' ')[0])
            normal_probability = float(lines[1].split(' ')[0])
        # 获取文件名
        filename = os.path.splitext(os.path.basename(file_path))[0]
        filename = filename + '.jpg'
        # 获取最大概率的名称
        #1正常0坑洼
        if normal_probability > potholes_probability:
            label = '1'
        else:
            label = '0'
        # 添加到结果列表
        result.append({'fnames': filename, 'label': label})
# 将结果保存为CSV文件
csv_file = 'G:/mod/testdata_V2/test_result.csv'
fieldnames = ['fnames', 'label']
with open(csv_file, 'w', newline='') as file:
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(result)
