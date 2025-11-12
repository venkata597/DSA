def N_Queens(board,row,n):
    if row == n:
        return True
    else:
        for col in range(n):
            if isSafe(board,row,col,n):
                board[row][col] = 1
                if N_Queens(board,row+1,n):
                    return True
                board[row][col] = 0
        return False

def isSafe(board,row,col,n):
    for i in range(row):
        if board[i][col] == 1:
            return False
    
    i,j = row-1,col-1
    while i>=0 and j>=0:
        if board[i][j] == 1:
            return False
        i-=1
        j-=1
    
    i,j = row-1,col+1
    while i>=0 and j < n:
        if board[i][j] == 1:
            return False
        i-=1
        j-=1

    return True

if __name__ == "__main__":
    N = 4  
    board = [[0 for _ in range(N)] for _ in range(N)]

    if N_Queens(board, 0, N):
        print("\nSolution found:\n")
        for row in board:
            print(row)
    else:
        print("No solution exists")
