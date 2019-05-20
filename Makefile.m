CC = g++

main: main.o MyString.o
	$(CC) main.o MyString.o -o main -g
main.o: main.cpp MyString.h
	$(CC) main.cpp -c -g
MyString.o: MyString.cpp MyString.h
	$(CC) MyString.cpp -c -g
