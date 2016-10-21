GCC = gcc -g

comp: linkedlist.c linkedlist.h mytunez.c mytunez.h
	$(GCC) linkedlist.c
	$(GCC) mytunez.c
	$(GCC) linkedlist.o mytunez.o -o songtest

run: comp
	./songtest

clean:
	rm *.o
	rm *~
