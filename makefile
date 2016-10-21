GCC = gcc -g

comp: linkedlist.c linkedlist.h mytunez.c mytunez.h
	$(GCC) linkedlist.c
	$(GCC) mytunez.c
	$(GCC) -o linkedlist.o mytunez.o songtest

run: comp
	./songtest

clean:
	rm *.o
	rm *~
