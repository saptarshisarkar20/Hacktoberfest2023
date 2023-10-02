def find_3_sum(arr):
    result = []
    arr.sort()

    i = 0
    while i < len(arr) - 2:
        start_idx = i + 1
        end_idx = len(arr) - 1

        # Because we sorted, the first number (arr[i]) can not be positive
        if arr[i] > 0:
            break

        while start_idx < end_idx:
            if arr[i] + arr[start_idx] + arr[end_idx] == 0:
                result.append([arr[i], arr[start_idx], arr[end_idx]])

                # Moving the pointer
                while start_idx < end_idx and arr[start_idx] == arr[start_idx + 1]:
                    start_idx += 1

                while start_idx < end_idx and arr[end_idx] == arr[end_idx - 1]:
                    end_idx -= 1

                start_idx += 1
                end_idx -= 1
            elif arr[i] + arr[start_idx] + arr[end_idx] < 0:
                start_idx += 1
            else:
                end_idx -= 1

        # Preventing duplicates
        while i < len(arr) - 3 and arr[i] == arr[i + 1]:
            i += 1

        i += 1

    return result

# Example usage:
arr = [-1, 0, 1, 2, -1, -4]
result = find_3_sum(arr)
print(result)
