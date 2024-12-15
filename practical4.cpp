def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

def display_top_scores(arr, top_n=5):
    print(f"Top {top_n} scores:")
    for score in arr[-top_n:]:
        print(score)

percentages = []
num_students = int(input("Enter the number of students: "))

for i in range(num_students):
    score = float(input(f"Enter the percentage for student {i + 1}: "))
    percentages.append(score)

selection_sort(percentages)
print("\nSorted percentages using Selection Sort:")
print(percentages)
display_top_scores(percentages)

bubble_sort(percentages)
print("\nSorted percentages using Bubble Sort:")
print(percentages)
display_top_scores(percentages)
