all:
	gcc -std=c11 -O3 -Wall -Werror -Wextra -Wshadow -Wpointer-arith -Wstrict-prototypes -Wmissing-prototypes -Wold-style-definition -Wvla -o gddr6 gddr6.c -lpci
clean:
	rm -f gddr6
install:
	cp gddr6 /usr/local/bin/
