
import os
import shutil

# 定义原始文件夹路径
original_folder = 'G:/mod/testdata_V2'


# 创建存放图片的文件夹
def create_folder(folder_path):
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)


# 定义每个子文件夹中的图片数量
images_per_folder = 1000
# 获取原始文件夹中的所有图片文件路径
image_files = [os.path.join(original_folder, filename) for filename in os.listdir(original_folder) if
               filename.endswith('.jpg')]
# 初始化子文件夹的索引
folder_index = 0
# 遍历每张图片
for index, image_file in enumerate(image_files):
    # 检查是否需要新的子文件夹
    if index % images_per_folder == 0:
        folder_index += 1
        folder_path = os.path.join(original_folder, f'folder_{folder_index}')
        create_folder(folder_path)

    # 移动图片文件到相应的子文件夹
    destination_folder = os.path.join(original_folder, f'folder_{folder_index}')
    shutil.move(image_file, destination_folder)
print("图片已成功分组存放。")