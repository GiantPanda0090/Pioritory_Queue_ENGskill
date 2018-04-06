#!/bin/bash
#plot 

counter=1
num=$(echo "$1+1" |bc )
while [ $counter -le $num ]
do
./build/linkedlist.o $counter $2
counter=$(echo "$counter+100" |bc )
done




