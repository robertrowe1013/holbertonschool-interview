#!/usr/bin/python3
""" log parse """
import sys
import signal

size = 0
i = 1
status_dict = {'200': 0, '301': 0, '400': 0, '401': 0,
               '403': 0, '404': 0, '405': 0, '500': 0}


def printall(sig=None, frame=None):
    """ print it """
    print("File size: {}".format(size))
    if status_dict['200'] > 0:
        print("200: {}".format(status_dict['200']))
    if status_dict['301'] > 0:
        print("301: {}".format(status_dict['301']))
    if status_dict['400'] > 0:
        print("400: {}".format(status_dict['400']))
    if status_dict['401'] > 0:
        print("401: {}".format(status_dict['401']))
    if status_dict['403'] > 0:
        print("403: {}".format(status_dict['403']))
    if status_dict['404'] > 0:
        print("404: {}".format(status_dict['404']))
    if status_dict['405'] > 0:
        print("405: {}".format(status_dict['405']))
    if status_dict['500'] > 0:
        print("500: {}".format(status_dict['500']))

try:
    for line in sys.stdin:
        line = line.split()
        size += int(line[-1])
        status_dict[line[-2]] += 1
        if i % 10 == 0:
            printall()
        i += 1

finally:
    printall()
    sys.stdout.flush()
