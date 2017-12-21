CC=gcc
SOURCE= src
CFLAGS=-std=c99 

make:
	rm -rf build	
	mkdir build	
	$(CC) $(CFLAGS) -g src/heap.c -o build/heap.o -lm
	$(CC) $(CFLAGS) -g src/linkedlist.c -o build/linkedlist.o	
	$(CC) $(CFLAGS) src/main.c -o build/main.o	
plot:
	./build/random > random.dat	
	gnuplot random.p
	display random.png
