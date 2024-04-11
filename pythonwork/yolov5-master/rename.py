import os

# 定义文件夹路径
folder_path = 'C:/Users/Administrator/Desktop/test/train/normal'

# 遍历文件夹中的所有文件
for filename in os.listdir(folder_path):
    # 构建原始文件的完整路径
    original_file = os.path.join(folder_path, filename)

    # 检查是否是图片文件
    if filename.lower().endswith(('.png', '.jpg', '.jpeg', '.gif')):
        # 获取文件夹名字
        folder_name = os.path.basename(folder_path)
        # 构建新的文件名
        new_filename = f"{folder_name}_{filename}"
        # 构建新文件的完整路径
        new_file = os.path.join(folder_path, new_filename)
        # 重命名文件
        os.rename(original_file, new_file)

print("图片已成功重命名。")
