# Fix My Code Challenge

## Project Overview
This project involves debugging and correcting issues in existing code for various tasks implemented in C, Python, and JavaScript. The focus is on understanding the existing codebase, fixing logic errors, and ensuring proper memory management.

### Directory Structure

```
Fix_My_Code_Challenge
│
├── README.md                  # Project overview and instructions
│
├── 0x00-challenge             # Main project directory
│   ├── 0-fizzbuzz.py          # Python file for the FizzBuzz challenge
│   ├── 1-print_square.js      # JavaScript file for printing a square
│   ├── 2-sort.rb              # Ruby file for sorting (not provided, placeholder)
│   ├── 3-user.py              # Python file for the User password challenge
│   └── 4-delete_dnodeint      # Directory for the double linked list challenge
│       ├── add_dnodeint_end.c # C file for adding node to the end of the list
│       ├── delete_dnodeint_at_index.c # C file for deleting a node at index
│       ├── free_dlistint.c    # C file for freeing the list
│       ├── lists.h            # Header file for linked list definitions
│       ├── main.c             # Main C file to test the linked list functions
│       └── print_dlistint.c   # C file for printing the list
│
└── LICENSE                    # Optional: License for the project
```

## 4-delete_dnodeint Subproject

### Description
This part of the project involves implementing and debugging functions for a doubly linked list, including:
- Adding a node at the end (`add_dnodeint_end.c`)
- Deleting a node at a specific index (`delete_dnodeint_at_index.c`)
- Printing the list (`print_dlistint.c`)
- Freeing the entire list (`free_dlistint.c`)

### Compilation and Execution
To compile the project, use:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c add_dnodeint_end.c delete_dnodeint_at_index.c free_dlistint.c print_dlistint.c -o dlistint_test
```

To run the compiled executable:
```bash
./dlistint_test
```

Memory Management Verification

This project was tested using `valgrind` to ensure there were no memory leaks:
```bash
valgrind --leak-check=full ./dlistint_test
```

## Result
All heap blocks were freed, confirming no memory leaks were present.

## Test Cases
The program was tested with various cases, including:
- Deleting nodes from different positions in the list (beginning, middle, end).
- Handling edge cases, such as deleting the last remaining node and attempting to delete from an empty list.
- Verifying outputs with debug statements for tracing operations (removed for the final version).

## Reference
This project is part of the ALX Software Engineering program. The original course and project repository can be found here: [ALX Tools - Fix My Code Challenge](https://github.com/alx-tools/0x00-Fix_My_Code_Challenge)

## Status
- The code has been debugged, tested, and verified to be free of memory leaks.
- The program runs correctly for all tested scenarios and handles edge cases as expected.

## Conclusion
This project provided an opportunity to practice debugging, memory management, and writing efficient C code for managing a doubly linked list.

