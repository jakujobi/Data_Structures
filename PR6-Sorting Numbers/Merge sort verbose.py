def merge_sort_verbose(arr, depth=0):
    """Sort the array using merge sort and print every step."""
    def merge(left, right):
        """Merge two sorted arrays."""
        merged, i, j = [], 0, 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                merged.append(left[i])
                i += 1
            else:
                merged.append(right[j])
                j += 1
        merged.extend(left[i:])
        merged.extend(right[j:])
        return merged

    n = len(arr)
    indent = "    " * depth  # Indentation for visual representation

    # Base case
    if n <= 1:
        return arr

    # Splitting the array
    mid = n // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # Recursive sorting
    sorted_left = merge_sort_verbose(left_half, depth + 1)
    sorted_right = merge_sort_verbose(right_half, depth + 1)

    # Merging sorted halves
    merged = merge(sorted_left, sorted_right)

    # Printing the current step
    print(indent + "   -   ".join(map(str, merged)) + "    //Combine into pairs" if depth > 0 else "   -   ".join(map(str, merged)))

    return merged

# The given array
arr = [43, 12, 32, 20, 14, 39, 21, 28, 48]

# Printing the original list of 9 elements
print("Original List of 9 elements:")
print("   -   ".join(map(str, arr)) + "    //Original List of 9 elements")
sorted_arr = merge_sort_verbose(arr)
print("Final Sorted List:")
print("   -   ".join(map(str, sorted_arr)) + "    //Final Sorted List")
