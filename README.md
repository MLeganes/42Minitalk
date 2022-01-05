# 42Minitalk

The purpose of this project is to code a small data exchange program using UNIX signals.

## Prerequisites

This project is for Mac OS.

## Installation

* `git@github.com:MLeganes/42Minitalk.git` this repository
* `cd 42Minitalk`

## Running
 
* `make`

* Run program with ``` ./minitalk```


## Sanitize
Add -g in gcc command.

	-fsanitize=leak
	-fsanitize=address

## Print traces
Add in header file this define:

	# define PRINT_HERE() (printf("file: %s, line: %d\n", __FILE__, __LINE__))

And used it from any part of your program

	PRINT_HERE();


## Testing with text file

	./client 48398 "`cat file-name` "

