#!/bin/bash
#plot 
echo "This script will run a complexity comparision for two different piority queue implementaion linkedlist vs skewheap"	
echo "preperation......"	
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
echo "compliling all component"
make
echo "SUCESSFUL COMPILED"
echo "simulation start"	
./run2.sh 5 1000 5 > plot/2/linkedlist.dat
echo "1st run"	
./run2.sh 5 1000 5 > plot/4/linkedlist.dat	
echo "2nd run"
./run2.sh 5 1000 5 > plot/6/linkedlist.dat
echo "3rd run"
echo "linked list done"	
./run1.sh 5 1000 5 > plot/2/heap.dat	
echo "1st run"
./run1.sh 5 1000 5 > plot/4/heap.dat	
echo "2nd run"
./run1.sh 5 1000 5 > plot/6/heap.dat
echo "3rd run"
echo "skew heap done"	
echo "1st data pattern done"	
./run1.sh 3  1000 6 > plot/8/heap.dat	
echo "1st run"
./run1.sh 3  1000 6 > plot/10/heap.dat
echo "2nd run"	
./run1.sh 3  1000 6 > plot/12/heap.dat
echo "3rd run"
echo "skew heap done"	
./run2.sh 3  1000 6 > plot/8/linkedlist.dat
echo "1st run"	
./run2.sh 3  1000 6 > plot/10/linkedlist.dat
echo "2nd run"	
./run2.sh 3  1000 6 > plot/12/linkedlist.dat
echo "3rd run"
echo "linkedlist done"	
echo "2nd data pattern done"
./run2.sh 6 1000 3 > plot/14/linkedlist.dat
echo "1st run"	
./run2.sh 6 1000 3 > plot/16/linkedlist.dat
echo "2nd run"	
./run2.sh 6 1000 3 > plot/18/linkedlist.dat
echo "3rd run"
echo "linked list done"
./run1.sh 6 1000 3 > plot/14/heap.dat
echo "1st run"	
./run1.sh 6 1000 3 > plot/16/heap.dat
echo "2nd run"	
./run1.sh 6 1000 3 > plot/18/heap.dat
echo "3rd run"
echo "skew heap done"			
echo "3rd data pattern done"
echo "SIMULATION SUECCESSED,PLOTING GRAPH......"
cd plot
gnuplot heap.p
echo "plot done!"
echo "open graph"
display heap.png
echo "not crashed!"

