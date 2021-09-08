#!/usr/bin/python3
"""Query reddit API for work count in hot list using recusion"""
import requests


def count_words(subreddit, word_list, next=None, count={}):
    """Count words in word_list in subreddit"""
    if next is None:
        subred_URL = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    else:
        subred_URL = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(
            subreddit, next)
    subreddit_req = requests.get(subreddit_URL,
                                 headers={"user-agent": "user"},
                                 allow_redirects=False)
    try:
        data = subreddit_req.json().get("data")
    except:
        return
