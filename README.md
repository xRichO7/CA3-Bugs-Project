# A Bug’s Life (C++ Simulation)

## Overview

A Bug’s Life is a C++ simulation game where different types of bugs move around a 10x10 board, fight each other, and survive until only one bug remains alive.

The program is fully menu-driven and uses object-oriented programming concepts such as:

* Inheritance
* Polymorphism
* Dynamic memory
* File handling

---

# Features

* Load bugs from a text file
* Display all bugs on the board
* Search for bugs by ID
* Move bugs around the board
* Simulate fights between bugs
* Track bug movement history
* Run the simulation until one winner remains
* Export life history results to an output file

---

# Bug Types

## Crawler

* Moves 1 step at a time
* Changes direction if blocked by the board edge

## Hopper

* Jumps multiple spaces using a hop length
* Picks a new direction if it cannot complete the jump

## Scorpion

* Moves in an L-shape similar to a knight in chess
* Chooses a new direction if blocked

---

# Combat System

After all bugs move:

* Bugs sharing the same cell fight each other
* Fights happen over multiple rounds
* Random damage is applied
* Bugs with health less than or equal to 0 die

The simulation continues until only one bug is left alive.

---

# Menu Options

1. Initialize Bug Board
2. Display all Bugs
3. Find a Bug by ID
4. Tap the Bug Board
5. Display Life History
6. Display all Cells and their Bugs
7. Run Full Simulation
8. Exit and Save Results

---

# Input File

The program reads bug data from:

```text
bugs.txt
```

Example formats:

## Crawler

```text
C;101;0;0;4;10
```

## Hopper

```text
H;102;9;0;1;8;2
```

## Scorpion

```text
S;111;1;1;2;14
```

---

# Output File

When the program exits, it creates a life history output file:

```text
bugs_life_history_YYYYMMDD_HHMMSS.out
```

The file contains:

* Bug type and ID
* Movement history
* Final status (Alive or Dead)

---

# Build Instructions

Using CMake:

```bash
cmake -S . -B build
cmake --build build
```

Executable:

```text
CA3_Bugs_Project
```

---

# Project Structure

* `Board.cpp` → board logic and combat
* `Crawler.cpp` → crawler movement
* `Hopper.cpp` → hopper movement
* `Scorpion.cpp` → scorpion movement
* `main.cpp` → menu system and program flow

---

# Notes

* Load the bugs before running the simulation
* The board size is fixed at 10x10
* Only alive bugs can move and fight
