GCC = gcc -g

comp: main.c linkedlist.c linkedlist.h mytunez.c mytunez.h
	$(GCC) -c linkedlist.c
	$(GCC) -c mytunez.c
	$(GCC) main.c linkedlist.o mytunez.o -o songtest

run: comp
	./songtest

clean:
	rm *.o
	rm *~
