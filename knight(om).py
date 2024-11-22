def displayBoard(chess):
    for i in range(len(chess)):
        for j in range(len(chess)):
            print(chess[i][j], "", end=" ")
        print()
    print()

def printKnightsTour(chess, n, r, c, upcomingMove, solution_count):
    if r < 0 or c < 0 or r >= n or c >= n or chess[r][c] != 0:
        return

    if solution_count[0] >= 10:
        return

    if upcomingMove == n * n:
        chess[r][c] = upcomingMove
        displayBoard(chess)
        chess[r][c] = 0
        solution_count[0]= solution_count[0]+ 1
        return

    chess[r][c] = upcomingMove

    # Recursively try all 8 possible moves of a knight
    printKnightsTour(chess, n, r - 2, c + 1, upcomingMove + 1, solution_count)
    printKnightsTour(chess, n, r - 1, c + 2, upcomingMove + 1, solution_count)
    printKnightsTour(chess, n, r + 1, c + 2, upcomingMove + 1, solution_count)
    printKnightsTour(chess, n, r + 2, c + 1, upcomingMove + 1, solution_count)
    printKnightsTour(chess, n, r + 2, c - 1, upcomingMove + 1, solution_count)
    printKnightsTour(chess, n, r + 1, c - 2, upcomingMove + 1, solution_count)
    printKnightsTour(chess, n, r - 1, c - 2, upcomingMove + 1, solution_count)
    printKnightsTour(chess, n, r - 2, c - 1, upcomingMove + 1, solution_count)

    chess[r][c] = 0

# Initialize the chessboard size and starting position
n = int(input("Enter the size of the chessboard (n x n): "))
start_row = int(input("Enter the starting row (0-based index): "))
start_col = int(input("Enter the starting column (0-based index): "))

# Create an empty chessboard
chessboard = []
for i in range(n):
    row = []
    for j in range(n):
        row.append(0)
    chessboard.append(row)

# Initialize solution counter
solution_counter = [0]

# Start the Knight's Tour with a limit of 10 solutions
print("Knight's Tour solutions (up to 10):")
printKnightsTour(chessboard, n, start_row, start_col, 1, solution_counter)

if solution_counter[0] == 0:
    print("No solutions found.")
else:
    print(f"Displayed {solution_counter[0]} solutions.")
