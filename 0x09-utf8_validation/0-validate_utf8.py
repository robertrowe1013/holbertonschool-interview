#!/usr/bin/python3
"""
Validate UTF8
"""


def validUTF8(data):

    if type(data) is not list:
        return False
    for num in data:
        if type(num) is not int:
            return False
        if num < 0:
            return False
    return True
