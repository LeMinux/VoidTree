#makefile for voidTree

compile:
	gcc -Wall driver.c voidPtrTree.c -o voidTree.out

debug:
	gcc -fsanitize=address -Wall -o debugTree.out driver.c voidPtrTree.c

gdb:
	gcc -g -Wall driver.c voidPtrTree.c -o debugTree.out

run:
	./voidTree.out

debugRun:
	./debugTree.out

gdbRun:
	gdb debugTree.out

clean:
	rm *.out
