make: done.o
	rm -rf build	
	mkdir build	
	gcc random.c -o build/random	
	RC=$?
plot:
	./build/random > random.dat	
	gnuplot random.p
	display random.png
