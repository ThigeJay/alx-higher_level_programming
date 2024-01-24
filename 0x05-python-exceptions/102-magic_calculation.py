#!/usr/bin/python3
def magic_calculation(a, b):
    # Initialize result to 0
    result = 0

    # Loop from 1 to 2 (exclusive)
    for i in range(1, 3):
        try:
            # Check if i is greater than a
            if i > a:
                # Raise an exception if i is too far
                raise Exception('Too far')

            # Update result by adding a^b divided by i
            result += a ** b / i

        except Exception:
            # Handle the exception by updating result to b + a
            result = b + a
            # Break out of the loop
            break

    # Return the final result
    return result
