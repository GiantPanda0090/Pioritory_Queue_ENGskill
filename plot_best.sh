#!/bin/bash
#plot 

prime1=1213
prime2=48239
prime3=3457549
prime4=120503
prime5=90019411
prime6=29
prime7=1230495757
prime9=149
prime10=48751
prime11=4839581
prime12=34631
prime8=78495847


echo "This script will run a complexity comparision for two different piority queue implementaion linkedlist vs skewheap"	
echo "preperation......"	

rm -rf plot/1
rm -rf plot/2
rm -rf plot/3
rm -rf plot/4
rm -rf plot/5
rm -rf plot/6
rm -rf plot/7
rm -rf plot/8
rm -rf plot/9
rm -rf plot/10
rm -rf plot/11
rm -rf plot/12
mkdir plot/1
mkdir plot/2
mkdir plot/3
mkdir plot/4
mkdir plot/5
mkdir plot/6
mkdir plot/7
mkdir plot/8
mkdir plot/9
mkdir plot/10
mkdir plot/11
mkdir plot/12



echo "compliling all component"
make
echo "SUCESSFUL COMPILED"
echo "simulation start"	
./run_list_best.sh $1 $2 0 $prime1 > plot/1/linkedlist.dat
echo "1st run"	
./run_list_best.sh $1 $2 0 $prime2 > plot/2/linkedlist.dat	
echo "2nd run"
./run_list_best.sh $1 $2 0 $prime3 > plot/3/linkedlist.dat
echo "3rd run"
./run_list_best.sh $1 $2 0 $prime4 > plot/4/linkedlist.dat
echo "4rd run"
echo "linked list done"	
./run_heap_best.sh $1 $2 0 $prime1 > plot/1/heap.dat	
echo "1st run"
./run_heap_best.sh $1 $2 0 $prime2 > plot/2/heap.dat	
echo "2nd run"
./run_heap_best.sh $1 $2 0 $prime3 > plot/3/heap.dat
echo "3rd run"
./run_heap_best.sh $1 $2 0 $prime4 > plot/4/heap.dat
echo "4rd run"
echo "skew heap done"	
echo "1st data pattern done"	
./run_heap_best.sh $1 $2 0 $prime9 > plot/5/heap.dat	
echo "1st run"
./run_heap_best.sh $1 $2 0 $prime10 > plot/6/heap.dat
echo "2nd run"	
./run_heap_best.sh $1 $2 0 $prime11 > plot/7/heap.dat
echo "3rd run"
./run_heap_best.sh $1 $2 0 $prime12 > plot/8/heap.dat
echo "4rd run"
echo "skew heap done"	
./run_list_best.sh $1 $2 0 $prime9 > plot/5/linkedlist.dat
echo "1st run"	
./run_list_best.sh $1 $2 0 $prime10 > plot/6/linkedlist.dat
echo "2nd run"	
./run_list_best.sh $1 $2 0 $prime11 > plot/7/linkedlist.dat
echo "3rd run"
./run_list_best.sh $1 $2 0 $prime12 > plot/8/linkedlist.dat
echo "4rd run"
echo "linkedlist done"	
echo "2nd data pattern done"
./run_list_best.sh $1 $2 0 $prime5 > plot/9/linkedlist.dat
echo "1st run"	
./run_list_best.sh $1 $2 0 $prime6 > plot/10/linkedlist.dat
echo "2nd run"	
./run_list_best.sh $1 $2 0 $prime7 > plot/11/linkedlist.dat
echo "3rd run"
./run_list_best.sh $1 $2 0 $prime8 > plot/12/linkedlist.dat
echo "4rd run"
echo "linked list done"
./run_heap_best.sh $1 $2 0 $prime5 > plot/9/heap.dat
echo "1st run"	
./run_heap_best.sh $1 $2 0 $prime6 > plot/10/heap.dat
echo "2nd run"	
./run_heap_best.sh $1 $2 0 $prime7 > plot/11/heap.dat
echo "3rd run"
./run_heap_best.sh $1 $2 0 $prime8 > plot/12/heap.dat
echo "4rd run"
echo "skew heap done"			
echo "3rd data pattern done"
echo "SIMULATION SUECCESSED,PLOTING GRAPH......"
rm heap.png
gnuplot plot/heap_avg.p
gnuplot plot/heap_logscale.p
gnuplot plot/heap_derivative.p
echo "plot done!"
echo "open graph"
display heap.png
display heap_logscale.png
display heap_derivative.png
echo "not crashed!"

