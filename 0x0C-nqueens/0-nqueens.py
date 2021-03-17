#!/usr/bin/python3
"""
N Queens
"""

import sys


def attacked(i, j):
    """
    is new queen safe

    check horizontal/vertical then check diagonals
    """
    for q in range(0, N):
        if board[i][q] == 1 or board[q][j] == 1:
            return True
    for q in range(0, N):
        for d in range(0, N):
            if (q + d == i + j) or (q - d == i - j):
                if board[q][d] == 1:
                    return True
    return False


def nqueen(n):
    """
    place queen
    """
    if n == 0:
        return True
    for i in range(0, N):
        for j in range(0, N):
            if (not(attacked(i, j))) and (board[i][j] != 1):
                board[i][j] = 1
                if nqueen(n - 1):
                    return True
                board[i][j] = 0
    return False

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        N = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)

    if N < 4:
        print("N must be at least 4")
        exit(1)

    board = [[0] * N for _ in range(N)]
    nqueen(N)
    solution_list = []
    for i in range(0, N):
        for j in range(0, N):
            if board[i][j] == 1:
                solution_list.append([i, j])
    print(solution_list)
    
