#!/usr/bin/python3
"""
Raises an exception.
"""


def raise_exception():
    raise TypeError("Exception raised")


if __name__ == "__main__":
    try:
        raise_exception()
    except TypeError as te:
        print("Exception raised")
