#!/bin/bash
#plot 





echo "This script will run a complexity comparision for two different piority queue implementaion linkedlist vs skewheap"	
echo "preperation......"

make

rm -rf avg/plot/*/linkedlist.dat
rm -rf avg/plot/*/heap.dat
prime_path=$4
if [ "$#" -ne 4 ]; then
    echo "erase prime list for new session"
    rm avg/plot/prime.txt
else
    echo "recreating previous session base on existant prime.txt file"
fi


echo "SUCESSFUL COMPILED"
echo "simulation start"	

counter=1
num=$(echo "$3+1" |bc )

while [ $counter -le $num ]
do

rm -rf avg/plot/$counter
mkdir avg/plot/$counter
rm -rf best/plot/$counter
mkdir best/plot/$counter
rm -rf worst/plot/$counter
mkdir worst/plot/$counter

prime=(python3 src/prime_gen.py 999 $prime_path $counter)

"${prime[@]}" >> avg/plot/prime.txt
env -i ./run_list.sh $1 $2 0 "${prime[@]}" > avg/plot/$counter/linkedlist.dat 
env -i ./run_heap.sh $1 $2 0 "${prime[@]}" > avg/plot/$counter/heap.dat 
env -i ./run_list_best.sh $1 $2 0 "${prime[@]}" > best/plot/$counter/linkedlist.dat
env -i ./run_heap_best.sh $1 $2 0 "${prime[@]}" > best/plot/$counter/heap.dat	
env -i ./run_list_worst.sh $1 $2 0 "${prime[@]}" > worst/plot/$counter/linkedlist.dat 
env -i ./run_heap_worst.sh $1 $2 0 "${prime[@]}" > worst/plot/$counter/heap.dat 
	
printf .
counter=$(echo "$counter+1" |bc )

done

echo
echo "SIMULATION SUECCESSED,PLOTING GRAPH......"


rm enqueue_avg.png
rm dequeue_avg.png

rm enqueue_logscale.png
rm dequeue_logscale.png

echo " processing average case data"

python3 avg/findmaxmin.py

gnuplot avg/plot/enqueue_avg.p
gnuplot avg/plot/dequeue_avg.p

gnuplot avg/plot/enqueue_logscale.p
gnuplot avg/plot/dequeue_logscale.p

rm avg/enqueue_avg.png
rm avg/dequeue_avg.png

rm avg/enqueue_logscale.png
rm avg/dequeue_logscale.png


echo "plot done!"
mv enqueue_avg.png avg/enqueue_avg.png
mv dequeue_avg.png avg/dequeue_avg.png
mv enqueue_logscale.png avg/enqueue_logscale.png
mv dequeue_logscale.png avg/dequeue_logscale.png


echo " processing best case data"

python3 best/findmaxmin.py

gnuplot best/plot/enqueue_avg.p
gnuplot best/plot/dequeue_avg.p

gnuplot best/plot/enqueue_logscale.p
gnuplot best/plot/dequeue_logscale.p

rm best/enqueue_avg.png
rm best/dequeue_avg.png

rm best/enqueue_logscale.png
rm best/dequeue_logscale.png

echo "plot done!"
mv enqueue_avg.png best/enqueue_avg.png
mv dequeue_avg.png best/dequeue_avg.png
mv enqueue_logscale.png best/enqueue_logscale.png
mv dequeue_logscale.png best/dequeue_logscale.png

echo " processing worst case data"

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



echo "General plot start"
gnuplot plot/'heap_logscale.p'
gnuplot plot/'heap_logscale_ll_all.p'
gnuplot plot/'heap_logscale_ll_dequeue_all.p'
gnuplot plot/'heap_logscale_skew_all.p'
gnuplot plot/'heap_logscale_skew_dequeue_all.p'
echo "plot done!"


echo "not crashed!"




