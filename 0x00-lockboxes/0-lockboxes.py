#!/usr/bin/python3


def canUnlockAll(boxes):
    '''
    """key for box 0, check for no boxes, unlock box 0"""
    unlockedBoxes = set([0])
    if boxes is None or len(boxes) <= 1:
        return True
    for keys in boxes[0]:
        openBox(keys, unlockedBoxes, boxes)
    if len(boxes) == len(unlockedBoxes):
        return True
    return False
    '''
    """without recusion"""
    unlockedBoxes = [0]
    openBoxes = 1

    for box in unlockedBoxes:
        for key in boxes[box]:
            if key < len(boxes) and key not in unlockedBoxes:
                unlockedBoxes.append(key)
                openBoxes += 1
    return openBoxes == len(boxes)


def openBox(keys, unlockedBoxes, boxes):
    """open box, if contains key to unopened box, open that box"""
    if keys < (len(boxes)) and keys not in unlockedBoxes:
        unlockedBoxes.add(keys)
        for key in boxes[keys]:
            openBox(key, unlockedBoxes, boxes)
