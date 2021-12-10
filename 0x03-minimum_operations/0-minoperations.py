#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """ number of min ops """
    if n < 2:
        return 0

    ops = 0
    total = 1
    copied = 0

    while total < n:
        if n % total == 0:
            copied = total
            ops += 1
        total += copied
        ops += 1
    if total == n:
        return ops
    return 0
