def find_first_mismatch(file1_path, file2_path):
    with open(file1_path, 'r') as file1, open(file2_path, 'r') as file2:
        content1 = file1.read().replace('\n', '')
        content2 = file2.read().replace('\n', '')

        min_length = min(len(content1), len(content2))

        for i in range(min_length):
            if content1[i] != content2[i]:
                print(f"First mismatch at index {i}")
                return

        if len(content1) != len(content2):
            print(f"Files have different lengths. Mismatch at index {min_length}")

        else:
            print("Files are identical.")

find_first_mismatch('output.txt', 'nasa.txt')
