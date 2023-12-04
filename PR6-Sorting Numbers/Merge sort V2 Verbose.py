def merge_sort(my_list):
    if len(my_list) > 1:
        mid = len(my_list) // 2
        left_half = my_list[:mid]
        right_half = my_list[mid:]

        print("\nSplitting:")
        print(left_half)
        print(right_half)

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = 0

        print("\nMerging:")
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                my_list[i + j] = left_half[i]
                i = i + 1
            else:
                my_list[i + j] = right_half[j]
                j = j + 1

        while i < len(left_half):
            my_list[i + j] = left_half[i]
            i = i + 1

        while j < len(right_half):
            my_list[i + j] = right_half[j]
            j = j + 1

        print(my_list)

    return my_list

# Define the original list of 9 elements
my_list = [43, 12, 32, 20, 14, 39, 21, 28, 48]
print("\nOriginal List of", len(my_list), "elements:")
print(my_list)

merge_sort(my_list)

print("\nMerge sort done, resulting list of", len(my_list), "elements:")
print(my_list)