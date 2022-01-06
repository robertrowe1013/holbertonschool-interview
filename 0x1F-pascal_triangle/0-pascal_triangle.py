#!/usr/bin/python3
"""Returns list of lists of pascals triangle"""


def pascal_triangle(n):
    """ n = height of triangle """
    triangle = []
    if n <= 0:
        return triangle
    for row in range(n):
        col = [None for i in range(row + 1)]
        col[0], col[-1] = 1, 1
        for i in range(1, len(col) - 1):
            col[i] = triangle[row - 1][i - 1] + triangle[row - 1][i]
        triangle.append(col)
    return triangle
