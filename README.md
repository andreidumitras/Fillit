# Fillit.
 - April 2017
 - Small group project
 - (c) Academy+Plus

# Description:
Fillit is a Tetris solver program that arranges the given pieces into the smalles square space.
The pieces are stored inside a file that is sent as a command line argument to the program.

The project was written during the first year of Academy+Plus and it was the second algorithms project for me. The project was initially designed for Linux/macOS.

# Usage:
To build the project, one must execute the Makefile:
```bash
make all
```
After the Makefile compiles the code, a new executable named *fillit* will be available. To test the program, I included some input samples inside the "exemple" directory.
```bash
# usage: "./fillit [filename]"
./fillit exemple/5.fillit
```
The input file must met the following requiremets:
 - the piece must have 4 collomns followed by a new line;
 - 4 lines per piece;
 - after each piece, there must be a SINGLE new line;
 - the file must end with the last piece. Any new line or other character is forbidden;
 - the piece must be described only by '.' and '#' characters. Any other character is also forbidden;
 - the piece must not be dislocated;

 The provided examples may clarify the criterias:
 - 1.fillit: OK
 - 2.fillit: OK
 - 3-problema.fillit: NOT OK
 - 4-problema.fillit: NOT OK
 - 5.fillit: OK
 - 6.fillit: OK
 - 7-problema.fillit: NOT OK
 - 8.fillit: OK
 - 9-problema.fillit: NOT OK
 - 10-problema.fillit: NOT OK
 - 11-problema.fillit: NOT OK
 - 12.fillit: OK
 - 13-problema.fillit: NOT OK

# Implementation:
The project has two main parts. The input verification part which verifies the input to be propperly constructed, and the solving part in which the solution is being constructed through backtracking. All the logic for the Fillit problem are placed inside the *source* directory.
The project has some aditional functions, together with some functions from Libft. These aditional functions are placed inside *functions* directory.
