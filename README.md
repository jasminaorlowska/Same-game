# Same-game
[wikipedia - same game](https://en.wikipedia.org/wiki/SameGame)
## Introduction 
A rectangular board for the single-player game SameGame is divided into cells, organized in rows and columns.
Each cell is either empty or contains a block of a specific type.
The player removes groups of adjacent blocks of the same type from the board.
Removing a group of blocks is only possible if there are at least two blocks in the group.
After removing a group, the board is rearranged:
Blocks fall into empty cells in the rows below.
Columns that still contain blocks are shifted to the left, filling in the empty column spaces.
The game is parameterized by three positive integers:
ROWS represents the number of rows on the board.
COLUMNS represents the number of columns on the board.
TYPES represents the number of block types.

## Compilation
gcc @opcje -DWIERSZE=10 -DKOLUMNY=15 -DRODZAJE=4 main.c -o main
where 1,2,3 parameters specify number of rows, columns and types of cells in the game

## About game
The input data for the program read from the input, is the current state of the board.

The output of the program written to the output, is the state of the board after the player's move.

The state of the board specifies, for each cell, whether it contains a block and if so, what type of block it is.

A set of G blocks on the board is called a **group** if the following three conditions are met:

- All blocks in the set G are of the same type.
- From any block in the set G, it is possible to reach any other block in the set by only moving
  to immediate neighbors in the same row or column, and only stepping on cells that contain blocks from the set G.
- The set G cannot be expanded without breaking rules 1 and 2.
- It can be observed that each block uniquely determines the group to which it belongs.

The program:
1. Reads the state of the board.
2. Checks if the cell at the coordinates specified by the program's arguments contains a block belonging to a group with at least two elements. If so, it removes all blocks of that group from the board.
3. Rearranges the board.
4. Writes the result.
   
When rearranging the board, the program:
1. While there is at least one block directly below which there is an empty cell in the same column, moves that block one position down.
2. While there is at least one non-empty column directly to the left of an empty column, moves all blocks in that non-empty column one position to the left.
3. If the cell at the coordinates specified by the program's arguments is empty or contains a block whose group has only one element, the program's output is the same as the input.

## Data

The number of rows in the program's data is determined by the constant WIERSZE. Each row is terminated by the end-of-line representation '\n'.

The number of characters in each row is determined by the constant KOLUMNY.

A data character specifies the content of a board cell:

The character '.' indicates that the cell is empty.
A decimal digit from '0' to '0' + RODZAJE - 1 represents the type of block.
The board described by the data is ordered. There is no block on the board with an empty cell below it. There is also no non-empty column to the left of which there is an empty column.
