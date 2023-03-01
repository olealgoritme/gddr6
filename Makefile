all:
	gcc -std=c99 -O3 -Wall -Wextra -o gddr6 gddr6.c -lpci 
clean:
	rm -f gddr6


