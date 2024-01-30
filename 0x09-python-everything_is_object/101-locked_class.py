#!/usr/bin/python3
"""
Defines a LockedClass that restricts the creation of instance attributes.

Module contains a class LockedClass with restrictions on dynamically creating
new instance attributes. The only allowed attribute is 'first_name'.
"""


class LockedClass:
    """
    Prevents the user from dynamically creating new instance attributes,
    except if the new instance attribute is called 'first_name'.
    """

    __slots__ = ["first_name"]
