
all: prog

prog: main.o temp_functions.o
	gcc -o prog main.o temp_functions.o

main.o: main.c 
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

cleanwin:
	del *.o prog prog.exe

cleanlin:
	rm *.o prog prog.exe
	