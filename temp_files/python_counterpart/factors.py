#!/usr/bin/python3
"""Please Note:

This python program was NOT used over its C-program counterpart due to
the obvoius speed exhibited by its C-program counterpart
"""

import sys


def print_factors(num):
    if num <= 1:
        sys.stderr.write(
            "Error: Number must be a valid integer greater than 1\n")
        return
    for i in range(2, num):
        if num % i == 0:
            temp = int(num / i)
            print("{:d}={:d}*{:d}".format(num, temp, i))
            return
    print("{} has no factors".format(num))


def main():
    # 1. INPUT
    try:
        fname = sys.argv[1]
        try:
            fhand = open(fname, 'r')
        except FileNotFoundError as file_err:
            sys.stderr.write("Error:" + str(file_err))
            sys.exit(1)
    except IndexError:
        sys.stderr.write("Usage: factors <file>")
        sys.exit(2)

    # 2. PROCESSING
    for line in fhand:
        line = line.strip()
        if line == "":
            break
        num = int(line)
        print_factors(num)

    # 3. CLOSE
    fhand.close()


if __name__ == "__main__":
    main()
