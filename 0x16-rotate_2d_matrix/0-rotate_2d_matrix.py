#!/usr/bin/python3
"""
rotate matrix
"""


def rotate_2d_matrix(matrix):
    """
    rotate matrix
    """
    for i in range(len(matrix)):
        for i2 in range(i, len(matrix)):
            if i != i2:
                matrix[i][i2], matrix[i2][i] = matrix[i2][i], matrix[i][i2]
        for i in matrix:
            i.reverse()
