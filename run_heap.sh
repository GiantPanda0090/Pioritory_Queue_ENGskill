#!/bin/bash
#plot 

counter=2
num=$(echo "$1+1" |bc )
while [ $counter -le $num ]
do

./build/heap.o $counter $2
counter=$(echo "$counter+$3" |bc )


done




