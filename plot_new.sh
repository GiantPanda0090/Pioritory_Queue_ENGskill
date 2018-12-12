#!/bin/bash
#plot 





echo "This script will run a complexity comparision for two different piority queue implementaion linkedlist vs skewheap"	
echo "preperation......"

make
rm -rf avg/plot/*/linkedlist.dat
rm -rf avg/plot/*/heap.dat
rm avg/plot/prime.txt

echo "SUCESSFUL COMPILED"
echo "simulation start"	

counter=1
num=$(echo "$3+1" |bc )
while [ $counter -le $num ]
do

rm -rf avg/plot/$counter
mkdir avg/plot/$counter
prime=(python3 src/prime_gen.py 999)

"${prime[@]}" >> avg/plot/prime.txt
env -i ./run_list.sh $1 $2 0 "${prime[@]}" > avg/plot/$counter/linkedlist.dat 
env -i ./run_heap.sh $1 $2 0 "${prime[@]}" > avg/plot/$counter/heap.dat 
printf .
counter=$(echo "$counter+1" |bc )

done
echo
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
echo "not crashed!"

