all: test

test: *.cpp
	g++ -lncurses *.cpp -o test