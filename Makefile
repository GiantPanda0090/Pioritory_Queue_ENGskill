make: done.o
	rm -rf build	
	mkdir build	
	gcc -std=c99 random.c -o build/random	
	RC=$?
plot:
	./build/random > random.dat	
	gnuplot random.p
	display random.png
