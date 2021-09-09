#!/usr/bin/python3
"""Query reddit API for work count in hot list using recusion"""
import requests


def count_words(subreddit, word_list, after=None, count={}):
    """Count words in word_list in subreddit"""
    if after is None:
        subred_URL = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    else:
        subred_URL = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(
            subreddit, after)
    subreddit_req = requests.get(subred_URL,
                                 headers={"user-agent": "user"},
                                 allow_redirects=False)
    try:
        data = subreddit_req.json().get("data")
    except:
        return
    for word in word_list:
        word = word.lower()
        if word not in count.keys():
            count[word] = 0
    children = data.get("children")
    for child in children:
        title = (child.get("data").get("title").lower())
        title = title.split(' ')
        for word in word_list:
            word = word.lower()
            count[word] += title.count(word)
    after = data.get("after")
    if after is not None:
        return count_words(subreddit, word_list, after, count)
    else:
        sorted_subs = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for i in sorted_subs:
            if i[1] != 0:
                print(i[0] + ": " + str(i[1]))
