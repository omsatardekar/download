def floydWarshall(graph):
    disVer = []
    for i in range(num_ver):
        row = []
        for j in range(num_ver):
            row.append(0)
        disVer.append(row)

    for row in range(0, num_ver):
        for col in range(0, num_ver):
            disVer[row][col] = graph[row][col]

    for k in range(0, num_ver):
        for row in range(0, num_ver):
            for col in range(0, num_ver):
                disVer[row][col] = min(disVer[row][col], (disVer[row][k] + disVer[k][col]))
        
        # Print matrix after each iteration of k
        print(f"After processing vertex {k + 1}:")
        for row in range(num_ver):
            for col in range(num_ver):
                if disVer[row][col] == 99999:  # Display infinity for large values
                    print("INF", end="\t")
                else:
                    print(disVer[row][col], end="\t")
            print()
        print()  # Blank line for better readability


num_ver = int(input("Enter no of vertices in graph: "))
inf = 99999
graph = []
for i in range(num_ver):
    row = []
    for j in range(num_ver):
        row.append(0)
    graph.append(row)

print("Enter Distances between given Vertices (99999 for Infinity):")
for row in range(0, num_ver):
    for col in range(0, num_ver):
        if row == col:
            graph[row][col] = 0
        else:
            graph[row][col] = int(input(f"{row+1} and {col+1}: "))

print("Graph is: ")
for row in range(0, num_ver):
    for col in range(0, num_ver):
        print(graph[row][col],end="\t")
    print("\n")
    
floydWarshall(graph)
