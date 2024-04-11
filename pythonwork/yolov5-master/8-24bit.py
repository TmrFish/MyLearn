from PIL import Image
import os

# 定义文件夹路径
folder_path = 'C:/Users/Administrator/Desktop/test'

# 遍历文件夹中的所有文件
for filename in os.listdir(folder_path):
    # 构建图片文件的完整路径
    image_path = os.path.join(folder_path, filename)

    # 检查是否是图片文件
    if filename.lower().endswith(('.png', '.jpg', '.jpeg', '.gif')):
        # 打开图片
        image = Image.open(image_path)

        # 检查图片的模式是否为 'P' (8-bit)
        if image.mode == 'P':
            # 创建一个新的 RGB 图片
            new_image = Image.new("RGB", image.size)

            # 将 8-bit 图片的每个像素复制到新的 RGB 图片中
            new_image.paste(image)



            # 保存为新的 24-bit 图片，替换原来的图片
            new_image.save(image_path)



            print(f"{filename} 转换完成。")
        else:
            print(f"{filename} 不是 8-bit 图片。")

