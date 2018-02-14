# All Target
all: apatil19_phone_directory

apatil19_phone_directory:	apatil19_phone_directory.o
	gcc -g apatil19_phone_directory.o -o apatil19_phone_directory.out

apatil19_phone_directory.o: apatil19_phone_directory.c   
	gcc -g -c apatil19_phone_directory.c

checkmem:	apatil19_phone_directory
	valgrind ./apatil19_phone_directory.out $(arg1)

run:	apatil19_phone_directory
	./apatil19_phone_directory.out $(arg1)

clean:
	rm -rf *.o apatil19_phone_directory.out 
