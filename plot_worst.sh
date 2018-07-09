#!/bin/bash
#plot 

prime1=493
prime2=799
prime3=323
prime4=999

prime5=12
prime6=234
prime7=49
prime8=415

prime9=4934
prime10=583
prime11=723
prime12=5134

prime13=56
prime14=3
prime15=654
prime16=79

prime17=1304
prime18=532
prime19=434
prime20=65


echo "This script will run a complexity comparision for two different piority queue implementaion linkedlist vs skewheap"
echo "preperation......"

make

rm -rf worst/plot/1
rm -rf worst/plot/2
rm -rf worst/plot/3
rm -rf worst/plot/4
rm -rf worst/plot/5
rm -rf worst/plot/6
rm -rf worst/plot/7
rm -rf worst/plot/8
rm -rf worst/plot/9
rm -rf worst/plot/10
rm -rf worst/plot/11
rm -rf worst/plot/12
rm -rf worst/plot/13
rm -rf worst/plot/14
rm -rf worst/plot/15
rm -rf worst/plot/16
rm -rf worst/plot/17
rm -rf worst/plot/18
rm -rf worst/plot/19
rm -rf worst/plot/20
mkdir worst/plot/1
mkdir worst/plot/2
mkdir worst/plot/3
mkdir worst/plot/4
mkdir worst/plot/5
mkdir worst/plot/6
mkdir worst/plot/7
mkdir worst/plot/8
mkdir worst/plot/9
mkdir worst/plot/10
mkdir worst/plot/11
mkdir worst/plot/12
mkdir worst/plot/13
mkdir worst/plot/14
mkdir worst/plot/15
mkdir worst/plot/16
mkdir worst/plot/17
mkdir worst/plot/18
mkdir worst/plot/19
mkdir worst/plot/20





echo "compliling all component"
make
echo "SUCESSFUL COMPILED"
echo "simulation start"	
./run_list_worst.sh $1 $2 0 $prime1 > worst/plot/1/linkedlist.dat 
echo "1st run"	
./run_list_worst.sh $1 $2 0 $prime2 > worst/plot/2/linkedlist.dat 	
echo "2nd run"
./run_list_worst.sh $1 $2 0 $prime3 > worst/plot/3/linkedlist.dat 
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime4 > worst/plot/4/linkedlist.dat 
echo "4rd run"
echo "linked list done"	


./run_heap_worst.sh $1 $2 0 $prime1 > worst/plot/1/heap.dat 	
echo "1st run"
./run_heap_worst.sh $1 $2 0 $prime2 > worst/plot/2/heap.dat 	
echo "2nd run"
./run_heap_worst.sh $1 $2 0 $prime3 > worst/plot/3/heap.dat 
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime4 > worst/plot/4/heap.dat 
echo "4rd run"
echo "skew heap done"	

echo "1st data pattern done"





./run_heap_worst.sh $1 $2 0 $prime9 > worst/plot/5/heap.dat 	
echo "1st run"
./run_heap_worst.sh $1 $2 0 $prime10 > worst/plot/6/heap.dat 
echo "2nd run"	
./run_heap_worst.sh $1 $2 0 $prime11 > worst/plot/7/heap.dat 
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime12 > worst/plot/8/heap.dat 
echo "4rd run"
echo "skew heap done"	
./run_list_worst.sh $1 $2 0 $prime9 > worst/plot/5/linkedlist.dat 
echo "1st run"	
./run_list_worst.sh $1 $2 0 $prime10 > worst/plot/6/linkedlist.dat 
echo "2nd run"	
./run_list_worst.sh $1 $2 0 $prime11 > worst/plot/7/linkedlist.dat 
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime12 > worst/plot/8/linkedlist.dat 
echo "4rd run"
echo "linkedlist done"	

echo "2nd data pattern done"



./run_list_worst.sh $1 $2 0 $prime5 > worst/plot/9/linkedlist.dat 
echo "1st run"	
./run_list_worst.sh $1 $2 0 $prime6 > worst/plot/10/linkedlist.dat 
echo "2nd run"	
./run_list_worst.sh $1 $2 0 $prime7 > worst/plot/11/linkedlist.dat 
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime8 > worst/plot/12/linkedlist.dat 
echo "4rd run"
echo "linked list done"
./run_heap_worst.sh $1 $2 0 $prime5 > worst/plot/9/heap.dat 
echo "1st run"	
./run_heap_worst.sh $1 $2 0 $prime6 > worst/plot/10/heap.dat 
echo "2nd run"	
./run_heap_worst.sh $1 $2 0 $prime7 > worst/plot/11/heap.dat 
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime8 > worst/plot/12/heap.dat 
echo "4rd run"
echo "skew heap done"	
		
echo "3rd data pattern done"



echo "5rd run"
echo "linkedlist done"
echo "2nd data pattern done"
./run_list_worst.sh $1 $2 0 $prime13 > worst/plot/13/linkedlist.dat 
echo "1st run"
./run_list_worst.sh $1 $2 0 $prime14 > worst/plot/14/linkedlist.dat 
echo "2nd run"
./run_list_worst.sh $1 $2 0 $prime15 > worst/plot/15/linkedlist.dat 
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime16> worst/plot/16/linkedlist.dat 
echo "4rd run"
echo "linked list done"
./run_heap_worst.sh $1 $2 0 $prime13 > worst/plot/13/heap.dat 
echo "1st run"
./run_heap_worst.sh $1 $2 0 $prime14 > worst/plot/14/heap.dat 
echo "2nd run"
./run_heap_worst.sh $1 $2 0 $prime15 > worst/plot/15/heap.dat 
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime16 > worst/plot/16/heap.dat 
echo "4rd run"
echo "linkedlist done"

echo "4th data pattern done"



./run_list_worst.sh $1 $2 0 $prime17 > worst/plot/17/linkedlist.dat 
echo "1st run"
./run_list_worst.sh $1 $2 0 $prime18 > worst/plot/18/linkedlist.dat 
echo "2nd run"
./run_list_worst.sh $1 $2 0 $prime19 > worst/plot/19/linkedlist.dat 
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime20 > worst/plot/20/linkedlist.dat 
echo "4rd run"
echo "linked list done"
./run_heap_worst.sh $1 $2 0 $prime17 > worst/plot/17/heap.dat 
echo "1st run"
./run_heap_worst.sh $1 $2 0 $prime18 > worst/plot/18/heap.dat 
echo "2nd run"
./run_heap_worst.sh $1 $2 0 $prime19 > worst/plot/19/heap.dat 
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime20 > worst/plot/20/heap.dat 
echo "4rd run"
echo "skew heap done"

echo "last data pattern done"



echo "SIMULATION SUECCESSED,PLOTING GRAPH......"




rm enqueue_avg.png
rm dequeue_avg.png

rm enqueue_logscale.png
rm dequeue_logscale.png

python3 worst/findmaxmin.py

gnuplot worst/plot/enqueue_avg.p
gnuplot worst/plot/dequeue_avg.p

gnuplot worst/plot/enqueue_logscale.p
gnuplot worst/plot/dequeue_logscale.p

rm worst/enqueue_avg.png
rm worst/dequeue_avg.png

rm worst/enqueue_logscale.png
rm worst/dequeue_logscale.png

echo "plot done!"
mv enqueue_avg.png worst/enqueue_avg.png
mv dequeue_avg.png worst/dequeue_avg.png
mv enqueue_logscale.png worst/enqueue_logscale.png
mv dequeue_logscale.png worst/dequeue_logscale.png
echo "open graph"
display worst/enqueue_avg.png
display worst/dequeue_avg.png
display worst/enqueue_logscale.png
display worst/dequeue_logscale.png
echo "not crashed!"
