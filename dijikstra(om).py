import heapq
from collections import defaultdict

def calculate_network_delay(edges, num_nodes, start_node):
    graph = defaultdict(list)

    # Build the graph from edges
    for source, target, weight in edges:
        graph[source].append((target, weight))

    # Initialize the priority queue with the start node
    min_heap = [(0, start_node)]
    dist = [float('inf')] * (num_nodes + 1)
    dist[start_node] = 0

    while min_heap:
        current_time, current_node = heapq.heappop(min_heap)

        # Skip processing if this is an outdated entry
        if current_time > dist[current_node]:
            continue

        # Update the time for neighbors if a shorter path is found
        for neighbor, weight in graph[current_node]:
            new_time = current_time + weight
            if new_time < dist[neighbor]:
                dist[neighbor] = new_time
                heapq.heappush(min_heap, (new_time, neighbor))

    # Find the maximum time to reach any node
    max_time = max(dist[1:])

    # If there's a node that is unreachable, return -1
    if max_time == float('inf'):
        return -1
    return dist[1:]

# Input for number of nodes and edges
num_nodes = int(input("Enter the number of nodes: "))
start_node = int(input("Enter the starting node: "))

# Input for the edges (source, target, weight)
edges = []
num_edges = int(input("Enter the number of edges: "))
for _ in range(num_edges):
    source, target, weight = map(int, input("Enter edge (source target weight): ").split())
    edges.append((source, target, weight))

# Call the function and display the result
print("Network Delay Times for all nodes: ", calculate_network_delay(edges, num_nodes, start_node))
