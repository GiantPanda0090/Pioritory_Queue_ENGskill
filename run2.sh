#!/bin/bash
#plot 

counter=1
while [ $counter -le $2 ]
do
./build/linkedlist.o $1 $counter $3
counter=$(echo "$counter+250" |bc )
done




