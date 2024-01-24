#!/usr/bin/python3
"""
Divides element by element in two lists using try/except/finally.
"""


def list_division(my_list_1, my_list_2, list_length):
    result = []
    for i in range(list_length):
        try:
            division_result = my_list_1[i] / my_list_2[i]
        except ZeroDivisionError:
            division_result = 0
            print("division by 0")
        except (ValueError, TypeError):
            division_result = 0
            print("wrong type")
        except IndexError:
            division_result = 0
            print("out of range")
        finally:
            result.append(division_result)
    return result


if __name__ == "__main__":
    my_l_1 = [10, 8, 4]
    my_l_2 = [2, 4, 4]
    result = list_division(my_l_1, my_l_2, max(len(my_l_1), len(my_l_2)))
    print(result)

    print("--")

    my_l_1 = [10, 8, 4, 4]
    my_l_2 = [2, 0, "H", 2, 7]
    result = list_division(my_l_1, my_l_2, max(len(my_l_1), len(my_l_2)))
    print(result)
