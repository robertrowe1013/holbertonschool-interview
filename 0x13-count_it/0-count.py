#!/usr/bin/python3
"""Query reddit API for work count in hot list"""


def count_words(subreddit, word_list):
    """Count words in word_list in subreddit"""

    if r.status_code != 200:
        return None