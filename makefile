all:
	g++ chip8.cpp main.cpp -o main.o -std=c++11

out:
	./main.o