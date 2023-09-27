import os
import shutil

source_folder = "C:\\Users\\jormg\\Desktop\\Python"  # Replace this with the actual source folder path
target_base_folder = "C:\\Users\\jormg\\Desktop\\Python"  # Replace this with the base target folder path
num_target_folders = 5

image_formats = [".jpg", ".jpeg", ".png", ".gif", ".bmp"]  # Add more formats if needed

def distribute_images(source_folder, target_base_folder, num_target_folders, image_formats):
    image_files = [f for f in os.listdir(source_folder) if f.lower().endswith(tuple(image_formats))]
    image_files.sort()  # Sort the image files to maintain the original order
    
    images_per_folder = len(image_files) // num_target_folders
    remainder = len(image_files) % num_target_folders

    for i in range(num_target_folders):
        target_folder_name = f"folder_{i+1}"
        target_folder_path = os.path.join(target_base_folder, target_folder_name)
        os.makedirs(target_folder_path, exist_ok=True)

        num_images_in_folder = images_per_folder + (1 if i < remainder else 0)

        for j in range(num_images_in_folder):
            if not image_files:
                break

            image_name = image_files.pop(0)
            source_path = os.path.join(source_folder, image_name)
            target_path = os.path.join(target_folder_path, image_name)
            
            shutil.move(source_path, target_path)
            print(f"Moved: {image_name} -> {target_path}")
 
distribute_images(source_folder, target_base_folder, num_target_folders, image_formats)
