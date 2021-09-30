#!/usr/bin/python3
"""
rotate matrix
"""


def rotate_2d_matrix(matrix):
    """
    rotate matrix
    """
    size = len(matrix) - 1
    for i in range(size):
        for j in range(i, size - i):
            temp = matrix[i][j]
            matrix[i][j] = matrix[size - j][i]
            matrix[size - j][i] = matrix[size - i][size - j]
            matrix[size - i][size - j] = matrix[j][size - i]
            matrix[j][size - i] = temp
