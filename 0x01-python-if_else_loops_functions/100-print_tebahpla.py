#!/usr/bin/python3
for char_code in range(ord('z'), ord('a') - 1, -1):
    if char_code % 2 == 0:
        offset = 0
    else:
        offset = 32
    print('{}'.format(chr(char_code - offset)), end='')
