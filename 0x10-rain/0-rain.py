#!/usr/bin/python3
"""
how much rain
"""


def rain(walls):
    """is trapped in the walls"""
    trappedrain = 0
    leftwall = 0
    rightwall = 0
    water = 0

    if len(walls) <= 2:
        return (0)

    for i in range(len(walls)):
        if walls[i] < leftwall:
            water += leftwall - walls[i]
        else:
            trappedrain += water
            water = 0
            leftwall = walls[i]
    water = 0
    leftwall = 0
    rightwall = 0
    walls.reverse()
    for i in range(len(walls)):
        if walls[i] < leftwall:
            water += leftwall - walls[i]
        else:
            trappedrain += water
            water = 0
            leftwall = walls[i]

    return (trappedrain)
