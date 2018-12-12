#!/bin/bash
#plot 

prime1=6977
prime2=799
prime3=323
prime4=999

prime5=7907
prime6=234
prime7=49
prime8=415

prime9=4934
prime10=583
prime11=723
prime12=5134

prime13=56
prime14=6907
prime15=654
prime16=79

prime17=1304
prime18=532
prime19=434
prime20=65

prime='python3 src/prime_gen.py 999'



echo "This script will run a complexity comparision for two different piority queue implementaion linkedlist vs skewheap"	
echo "preperation......"

make


rm -rf avg/plot/1
rm -rf avg/plot/2
rm -rf avg/plot/3
rm -rf avg/plot/4
rm -rf avg/plot/5
rm -rf avg/plot/6
rm -rf avg/plot/7
rm -rf avg/plot/8
rm -rf avg/plot/9
rm -rf avg/plot/10
rm -rf avg/plot/11
rm -rf avg/plot/12
rm -rf avg/plot/13
rm -rf avg/plot/14
rm -rf avg/plot/15
rm -rf avg/plot/16
rm -rf avg/plot/17
rm -rf avg/plot/18
rm -rf avg/plot/19
rm -rf avg/plot/20
mkdir avg/plot/1
mkdir avg/plot/2
mkdir avg/plot/3
mkdir avg/plot/4
mkdir avg/plot/5
mkdir avg/plot/6
mkdir avg/plot/7
mkdir avg/plot/8
mkdir avg/plot/9
mkdir avg/plot/10
mkdir avg/plot/11
mkdir avg/plot/12
mkdir avg/plot/13
mkdir avg/plot/14
mkdir avg/plot/15
mkdir avg/plot/16
mkdir avg/plot/17
mkdir avg/plot/18
mkdir avg/plot/19
mkdir avg/plot/20





echo "SUCESSFUL COMPILED"
echo "simulation start"	
./run_list.sh $1 $2 0 $prime > avg/plot/1/linkedlist.dat 
echo "1st run"	
./run_list.sh $1 $2 0 $prime2 > avg/plot/2/linkedlist.dat 	
echo "2nd run"
./run_list.sh $1 $2 0 $prime3 > avg/plot/3/linkedlist.dat 
echo "3rd run"
./run_list.sh $1 $2 0 $prime4 > avg/plot/4/linkedlist.dat 
echo "4rd run"
echo "linked list done"	
./run_heap.sh $1 $2 0 $prime1 > avg/plot/1/heap.dat 	
echo "1st run"
./run_heap.sh $1 $2 0 $prime2 > avg/plot/2/heap.dat 	
echo "2nd run"
./run_heap.sh $1 $2 0 $prime3 > avg/plot/3/heap.dat 
echo "3rd run"
./run_heap.sh $1 $2 0 $prime4 > avg/plot/4/heap.dat 
echo "4rd run"
echo "skew heap done"	

echo "1st data pattern done"



./run_heap.sh $1 $2 0 $prime9 > avg/plot/5/heap.dat 	
echo "1st run"
./run_heap.sh $1 $2 0 $prime10 > avg/plot/6/heap.dat 
echo "2nd run"	
./run_heap.sh $1 $2 0 $prime11 > avg/plot/7/heap.dat 
echo "3rd run"
./run_heap.sh $1 $2 0 $prime12 > avg/plot/8/heap.dat 
echo "4rd run"
echo "skew heap done"	
./run_list.sh $1 $2 0 $prime9 > avg/plot/5/linkedlist.dat 
echo "1st run"	
./run_list.sh $1 $2 0 $prime10 > avg/plot/6/linkedlist.dat 
echo "2nd run"	
./run_list.sh $1 $2 0 $prime11 > avg/plot/7/linkedlist.dat 
echo "3rd run"
./run_list.sh $1 $2 0 $prime12 > avg/plot/8/linkedlist.dat 
echo "4rd run"
echo "linkedlist done"	

echo "2nd data pattern done"



./run_list.sh $1 $2 0 $prime5 > avg/plot/9/linkedlist.dat 
echo "1st run"	
./run_list.sh $1 $2 0 $prime6 > avg/plot/10/linkedlist.dat 
echo "2nd run"	
./run_list.sh $1 $2 0 $prime7 > avg/plot/11/linkedlist.dat 
echo "3rd run"
./run_list.sh $1 $2 0 $prime8 > avg/plot/12/linkedlist.dat 
echo "4rd run"
echo "linked list done"
./run_heap.sh $1 $2 0 $prime5 > avg/plot/9/heap.dat 
echo "1st run"	
./run_heap.sh $1 $2 0 $prime6 > avg/plot/10/heap.dat 
echo "2nd run"	
./run_heap.sh $1 $2 0 $prime7 > avg/plot/11/heap.dat 
echo "3rd run"
./run_heap.sh $1 $2 0 $prime8 > avg/plot/12/heap.dat 
echo "4rd run"
echo "linkedlist done"
echo "3rd data pattern done"
./run_list.sh $1 $2 0 $prime13 > avg/plot/13/linkedlist.dat 
echo "1st run"
./run_list.sh $1 $2 0 $prime14 > avg/plot/14/linkedlist.dat 
echo "2nd run"
./run_list.sh $1 $2 0 $prime15 > avg/plot/15/linkedlist.dat 
echo "3rd run"
./run_list.sh $1 $2 0 $prime16 > avg/plot/16/linkedlist.dat 
echo "4rd run"
echo "linked list done"
./run_heap.sh $1 $2 0 $prime13 > avg/plot/13/heap.dat 
echo "1st run"
./run_heap.sh $1 $2 0 $prime14 > avg/plot/14/heap.dat 
echo "2nd run"
./run_heap.sh $1 $2 0 $prime15 > avg/plot/15/heap.dat 
echo "3rd run"
./run_heap.sh $1 $2 0 $prime16 > avg/plot/16/heap.dat 
echo "4rd run"
echo "linkedlist done"

echo "4th data pattern done"



./run_list.sh $1 $2 0 $prime17 > avg/plot/17/linkedlist.dat 
echo "1st run"
./run_list.sh $1 $2 0 $prime18 > avg/plot/18/linkedlist.dat 
echo "2nd run"
./run_list.sh $1 $2 0 $prime19 > avg/plot/19/linkedlist.dat 
echo "3rd run"
./run_list.sh $1 $2 0 $prime20 > avg/plot/20/linkedlist.dat 
echo "4rd run"
echo "linked list done"
./run_heap.sh $1 $2 0 $prime17 > avg/plot/17/heap.dat 
echo "1st run"
./run_heap.sh $1 $2 0 $prime18 > avg/plot/18/heap.dat 
echo "2nd run"
./run_heap.sh $1 $2 0 $prime19 > avg/plot/19/heap.dat 
echo "3rd run"
./run_heap.sh $1 $2 0 $prime20 > avg/plot/20/heap.dat 
echo "4rd run"
echo "skew heap done"			
echo "last data pattern done"

echo "SIMULATION SUECCESSED,PLOTING GRAPH......"


rm enqueue_avg.png
rm dequeue_avg.png

rm enqueue_logscale.png
rm dequeue_logscale.png

python3 avg/findmaxmin.py

gnuplot avg/plot/enqueue_avg.p
gnuplot avg/plot/dequeue_avg.p

gnuplot avg/plot/enqueue_logscale.p
gnuplot avg/plot/dequeue_logscale.p

rm avg/enqueue_avg.png
rm avg/dequeue_avg.png

rm avg/enqueue_logscale.png
rm avg/dequeue_logscale.png


gnuplot plot/'heap_logscale.p'
gnuplot plot/'heap_logscale_ll_all.p'
gnuplot plot/'heap_logscale_ll_dequeue_all.p'
gnuplot plot/'heap_logscale_skew_all.p'
gnuplot plot/'heap_logscale_skew_dequeue_all.p'

echo "plot done!"
mv enqueue_avg.png avg/enqueue_avg.png
mv dequeue_avg.png avg/dequeue_avg.png
mv enqueue_logscale.png avg/enqueue_logscale.png
mv dequeue_logscale.png avg/dequeue_logscale.png
echo "open graph"
display avg/enqueue_avg.png
display avg/dequeue_avg.png
display avg/enqueue_logscale.png
display avg/dequeue_logscale.png
echo "not crashed!"

