import os

def rename_images(folder_path):
    image_formats = ['.jpg', '.jpeg', '.png', '.gif', '.bmp']  # Add more formats if needed
    image_files = [f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f)) and any(f.lower().endswith(ext) for ext in image_formats)]
    image_files.sort()

    for index, image_file in enumerate(image_files):
        file_extension = os.path.splitext(image_file)[1]
        new_name = f"Jordan_{index + 1:03d}{file_extension}"
        old_path = os.path.join(folder_path, image_file)
        new_path = os.path.join(folder_path, new_name)
        os.rename(old_path, new_path)
        print(f"Renamed {image_file} to {new_name}")

if __name__ == "__main__":
    folder_path = 'C:\\Users\\jormg\\Desktop\\Python'  # Replace with your folder path
    rename_images(folder_path)
