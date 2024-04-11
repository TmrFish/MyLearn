import os
import shutil

# 指定当前文件夹路径和目标文件夹路径
current_folder = 'G:/work/pythonwork/yolov5-master/runs/predict-cls/exp6'
target_folder = 'G:/mod/testdata_V2/mistakejpg'

# 读取 txt 文件
with open('G:/mod/testdata_V2/mistake.txt', 'r') as txt_file:
    file_names = txt_file.read().splitlines()

# 遍历当前文件夹中的文件
for filename in os.listdir(current_folder):
    # 检查文件是否为 jpg 格式且在指定的文件名列表中
    if filename.lower().endswith('.jpg') and filename in file_names:
        # 构建当前文件和目标文件的完整路径
        current_file = os.path.join(current_folder, filename)
        target_file = os.path.join(target_folder, filename)

        # 将文件复制到目标文件夹中
        shutil.copy2(current_file, target_file)

        print(f"{filename} 已复制到目标文件夹中。")

