#!/usr/bin/python3
if __name__ == "__main__":
    from add_0 import add

    # Assign values to variables
    a = 1
    b = 2

    # Print the result of the addition
    print("{:d} + {:d} = {:d}".format(a, b, add(a, b)))
