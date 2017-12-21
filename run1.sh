#!/bin/bash
#plot 

counter=0
while [ $counter -le $2 ]
do
./build/heap.o $1 $counter $3
counter=$(echo "$counter+100" |bc )
done




