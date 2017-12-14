#!/bin/bash
#plot for mac

./build/heap > heap.dat	
./build/linkedlist > linkedlist.dat	
gnuplot plot.p
display plot.png
