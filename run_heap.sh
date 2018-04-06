#!/bin/bash
#plot 

counter=1
num=$(echo "$1+1" |bc )
while [ $counter -le $num ]
do
./build/heap.o $counter
counter=$(echo "$counter+100" |bc )

done




