#!/bin/bash
#plot 

counter=1
num=$(echo "$2+1" |bc )
while [ $counter -le $num ]
do
./build/heap.o $1 $counter $3
counter=$(echo "$counter+100" |bc )
done




