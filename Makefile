CC=gcc
SOURCE= src
CFLAGS=-std=c99 

make:
	rm -rf build	
	mkdir build	
	$(CC) $(CFLAGS) -g src/heap.c src/print_ascii.c	src/rand_gen.c -o build/heap.o -lm -lrt
	$(CC) $(CFLAGS) -g src/heap_best.c src/print_ascii.c	src/rand_gen.c	-o build/heap_best.o -lm   -lrt
	$(CC) $(CFLAGS) -g src/heap_worst.c src/print_ascii.c	src/rand_gen.c	 -o build/heap_worst.o -lm -lrt
	$(CC) $(CFLAGS) -g src/linkedlist.c src/rand_gen.c	-o	build/linkedlist.o -lm   -lrt
	$(CC) $(CFLAGS) -g src/linkedlist_best.c src/rand_gen.c	-o build/linkedlist_best.o -lm -lrt
	$(CC) $(CFLAGS) -g src/linkedlist_worst.c src/rand_gen.c	-o build/linkedlist_worst.o -lm   -lrt
makeall:
	rm -rf build	
	mkdir build	
	$(CC) -g src/heap.c -o build/heap.o
	$(CC) -g src/linkedlist.c -o build/linkedlist.o	
plot:
	./build/random > random.dat	
	gnuplot random.p
	display random.png
