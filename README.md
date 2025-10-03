
# Linked List Data Structures in C

[![Language: C](https://img.shields.io/badge/Language-C-555555?style=flat-square)](https://www.cprogramming.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?style=flat-square)](LICENSE)

## Project Structure

```
linked-list-project/
│
├── main.c        # Main menu and program entry
├── sll.h         # Singly Linked List header
├── sll.c         # Singly Linked List implementation
├── dll.h         # Doubly Linked List header
├── dll.c         # Doubly Linked List implementation
├── csll.h        # Circular Singly Linked List header
├── csll.c        # Circular Singly Linked List implementation
├── cdll.h        # Circular Doubly Linked List header
├── cdll.c        # Circular Doubly Linked List implementation
└── README.md     # Project documentation
```
---

## How to Compile and Run

### Compile on Linux / macOS / Windows (with GCC)

```bash
gcc main.c sll.c dll.c csll.c cdll.c -o linkedlist
```

### Run the program

```bash
./linkedlist    # Linux / macOS
linkedlist.exe  # Windows
```

---

## Usage

1. **Main Menu**: Choose the type of linked list (SLL, DLL, CSLL, CDLL).  
2. **List Menu**: Perform operations such as insert, delete, traverse, sort, reverse, etc.  
3. Enter `-1` when creating a new list to stop adding initial elements.  
4. Exit a specific list menu to return to the main menu.

---

## Example Output

```
==== Main Menu ====
1. Singly Linked List (SLL)
2. Doubly Linked List (DLL)
3. Circular SLL (CSLL)
4. Circular DLL (CDLL)
5. Exit
Enter choice: 1

--- SLL Menu ---
1. Create New List
2. Traverse
...
Enter choice: 1
Enter elements (-1 stop): 10 20 30 -1
List created successfully!
```

---

## Features & Learning Outcomes

- Hands-on practice with **dynamic memory allocation** (`malloc` / `free`)  
- Understanding **pointer manipulation** in linear, doubly-linked, and circular lists  
- Modular programming using **header files** and **separate implementation files**  
- Menu-driven programs with **user input validation**  

---

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
