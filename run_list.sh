#!/bin/bash
#plot 

counter=2
num=$(echo "$1+1" |bc )
while [ $counter -le $num ]
do

./build/linkedlist.o $counter $3 $4
counter=$(echo "$counter+$2" |bc )
done



