#!/bin/bash
#plot for mac

./build/heap.o 5 18 5 > plot/heap.dat	
cd plot
gnuplot heap.p
display heap.png
