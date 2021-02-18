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
    dataList = []

    for num in data:
        try:
            dataList.append(num.to_bytes(1, 'big'))
        except OverflowError:
            dataList.append(num.to_bytes(2, 'big'))
        test = b''.join(dataList)

    try:
        test.decode('utf-8')
    except UnicodeDecodeError:
        return False

    return True
