#!/bin/bash
#plot 

counter=1000
num=$(echo "$1+1" |bc )
while [ $counter -le $num ]
do

./build/heap_worst.o $counter $3 $4
counter=$(echo "$counter+$2" |bc )


done




