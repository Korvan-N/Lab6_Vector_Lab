# Lab6 Vector Lab
### Korvan Nameni
Program is meant to simulate matlab with a vector calculator functionality.

### valid commands:
```
▪ vector = float, float, float
▪ vector + vector
▪ vector - vector
▪ vector * float
▪ float * vector
▪ vector = vector (+ -) vector
▪ vector = vector * float
▪ clear
▪ list
▪ quit
▪ load <filename>
▪ save <filename>
```

note: spaces are REQUIRED around equal signs.
note: max 100 characters per line.

## how to build:
in the command line: `make`

## How to run:
in the command line after you've built:
2. ./lab7
3. run any command listed above as needed.
4. exit the program with `quit`.

## Dynamic memory in the program:
program uses a struct pointer `vectors` which keeps track of the current vectors. To add a vector, the vector count increases by 1. Then pointer size gets reallocated with `realloc()`, the input being the size of the struct multiplied by the vector count. the pointer is reallocated after every insertion of data. to remove all vectors, `free(vectors)` is used. 