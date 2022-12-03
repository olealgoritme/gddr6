all:
	gcc -O3 -Wall -o gddr6 gddr6.c -lpci
clean:
	rm -f gddr6


