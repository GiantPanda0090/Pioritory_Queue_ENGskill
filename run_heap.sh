#!/bin/bash
#plot 

counter=2
num=$(echo "$1+1" |bc )
while [ $counter -le $num ]
do

./build/heap.o $counter
counter=$(echo "$counter+$2" |bc )


done




