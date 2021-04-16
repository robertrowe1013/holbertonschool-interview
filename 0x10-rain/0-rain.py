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
    tallest = max(walls)

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
    if walls[0] == tallest and walls[len(walls) - 1] == tallest:
        return (trappedrain)
    walls.reverse()
    for i in range(len(walls)):
        if walls[i] < leftwall:
            water += leftwall - walls[i]
        else:
            trappedrain += water
            water = 0
            leftwall = walls[i]

    return (trappedrain)
