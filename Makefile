sudoku : check.c main.c str.c sudoku.h
	gcc -o sudoku -Wall -Werror -Wextra main.c check.c str.c 

norm :	check.c main.c str.c sudoku.h
	norminette check.c main.c str.c sudoku.h

clean :
	rm sudoku
