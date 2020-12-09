#!/usr/bin/python3


def canUnlockAll(boxes):
    """key for box 0, check for no boxes, unlock box 0"""
    unlockedBoxes = set([0])
    if boxes is None or len(boxes) <= 1:
        return True
    for keys in boxes[0]:
        openBox(keys, unlockedBoxes, boxes)
    if len(boxes) == len(unlockedBoxes):
        return True
    return False


def openBox(keys, unlockedBoxes, boxes):
    """open box, if contains key to unopened box, open that box"""
    if keys < (len(boxes)) and keys not in unlockedBoxes:
        unlockedBoxes.add(keys)
        for keys in boxes[keys]:
            openBox(keys, unlockedBoxes, boxes)
