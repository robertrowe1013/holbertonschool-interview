#!/usr/bin/python3


def canUnlockAll(boxes):
    """unlock the box"""
    unlockedBoxes = set([0])
    for keys in boxes[0]:
        openBox(keys, unlockedBoxes, boxes)
    if len(boxes) == len(unlockedBoxes):
        return True
    return False


def openBox(keys, unlockedBoxes, boxes):
    """open box"""
    if keys < (len(boxes)) and keys not in unlockedBoxes:
        unlockedBoxes.add(keys)
        for keys in boxes[keys]:
            openBox(keys, unlockedBoxes, boxes)
