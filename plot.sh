#!/bin/bash
#plot 
cd plot
rm -rf 2
rm -rf 4
rm -rf 6
rm -rf 8
rm -rf 10
rm -rf 12
rm -rf 14
rm -rf 16
rm -rf 18
mkdir 2
mkdir 4
mkdir 6
mkdir 8
mkdir 10
mkdir 12
mkdir 14
mkdir 16
mkdir 18
cd ..
./run1.sh 900 10000 50 > plot/2/heap.dat	
./run1.sh 900 10000 50 > plot/4/heap.dat	
./run1.sh 900 10000 50 > plot/6/heap.dat	
./run1.sh 1000 10000 50 > plot/8/heap.dat	
./run1.sh 1000 10000 50 > plot/10/heap.dat	
./run1.sh 1000 10000 50 > plot/12/heap.dat
./run1.sh 1100 10000 50 > plot/14/heap.dat	
./run1.sh 1100 10000 50 > plot/16/heap.dat	
./run1.sh 1100 10000 50 > plot/18/heap.dat	
cd plot
gnuplot heap.p
display heap.png
