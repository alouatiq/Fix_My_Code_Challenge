#!/usr/bin/python3
"""
FizzBuzz Program

This script implements the classic FizzBuzz problem. It takes a single
integer `n` as input from the command line and prints numbers from 1 to `n`,
separated by a space, with the following rules:

- For multiples of three, "Fizz" is printed instead of the number.
- For multiples of five, "Buzz" is printed instead of the number.
- For numbers that are multiples of both three and five, "FizzBuzz" is printed.

If no number is provided as an argument, the program will display usage instructions.
"""

import sys


def fizzbuzz(n):
    """
    FizzBuzz function prints numbers from 1 to n, following the FizzBuzz rules.

    Parameters:
        n (int): The upper limit of the range (inclusive).

    Behavior:
        - For multiples of 3, outputs "Fizz".
        - For multiples of 5, outputs "Buzz".
        - For multiples of both 3 and 5, outputs "FizzBuzz".
        - For all other numbers, outputs the number itself.
    """
    if n < 1:
        return

    tmp_result = []
    for i in range(1, n + 1):
        if (i % 3) == 0 and (i % 5) == 0:
            tmp_result.append("FizzBuzz")
        elif (i % 3) == 0:
            tmp_result.append("Fizz")
        elif (i % 5) == 0:
            tmp_result.append("Buzz")
        else:
            tmp_result.append(str(i))
    print(" ".join(tmp_result))


if __name__ == '__main__':
    # Ensure that a number is passed as an argument
    if len(sys.argv) <= 1:
        print("Missing number")
        print("Usage: ./0-fizzbuzz.py <number>")
        print("Example: ./0-fizzbuzz.py 89")
        sys.exit(1)

    try:
        number = int(sys.argv[1])
        fizzbuzz(number)
    except ValueError:
        print("Invalid input: Please provide a valid integer.")
        sys.exit(1)
