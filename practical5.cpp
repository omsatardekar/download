def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

def display_top_scores(arr, top_n=5):
    print(f"Top {top_n} scores (from max to min):")
    for score in sorted(arr[-top_n:], reverse=True):
        print(score)

percentages = []
while True:
    try:
        num_students = int(input("Enter the number of students: "))
        if num_students <= 0:
            raise ValueError("Number of students must be a positive integer.")
        break
    except ValueError as e:
        print(f"Invalid input: {e}. Please try again.")

for i in range(num_students):
    while True:
        try:
            score = float(input(f"Enter the percentage for student {i + 1}: "))
            percentages.append(score)
            break
        except ValueError:
            print("Invalid input. Please enter a valid number.")

insertion_sort(percentages)
print("\nSorted percentages using Insertion Sort:")
print(percentages)
display_top_scores(percentages)

shell_sort(percentages)
print("\nSorted percentages using Shell Sort:")
print(percentages)
display_top_scores(percentages)