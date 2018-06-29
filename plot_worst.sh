#!/bin/bash
#plot 

prime1=54353856574684354373968954429
prime2=45213787564217878695342348945312498641
prime3=7867354123486432465868541215648645313246533207
prime4=124983465683534432185646875643456748745125546857354241461

prime5=99565656535354432156753454248634385746845591
prime6=2351468748578435111113546477
prime7=32543393365424324887653218743654954132165468949892638591
prime8=56856865358374234113545161

prime9=454532123135457535156845452345735498539857899
prime10=55968967867864352484689435435484548732161
prime11=8855445333221166998523214562314579
prime12=78234423135453124361

prime13=44444444222365321365476846854534874837483176876854491
prime14=1354874567435757867897875435552484973547
prime15=7542375735484324185476875412468468531
prime16=11111111111113265674687987654354357468748635132473535353583567354423

prime17=16052176553459
prime18=354768746871878746874165423748864534787968475379
prime19=47459886333244663636612837895243798281
prime20=456887134415786774688194324658676743984612834326352451



echo "This script will run a complexity comparision for two different piority queue implementaion linkedlist vs skewheap"
echo "preperation......"

free && sync && echo 3 > /proc/sys/vm/drop_caches && free

rm -rf worst/plot/1
rm -rf worst/plot/2
rm -rf worst/plot/3
rm -rf worst/plot/4
rm -rf worst/plot/5
rm -rf worst/plot/6
rm -rf worst/plot/7
rm -rf worst/plot/8
rm -rf worst/plot/9
rm -rf worst/plot/10
rm -rf worst/plot/11
rm -rf worst/plot/12
rm -rf worst/plot/13
rm -rf worst/plot/14
rm -rf worst/plot/15
rm -rf worst/plot/16
rm -rf worst/plot/17
rm -rf worst/plot/18
rm -rf worst/plot/19
rm -rf worst/plot/20
mkdir worst/plot/1
mkdir worst/plot/2
mkdir worst/plot/3
mkdir worst/plot/4
mkdir worst/plot/5
mkdir worst/plot/6
mkdir worst/plot/7
mkdir worst/plot/8
mkdir worst/plot/9
mkdir worst/plot/10
mkdir worst/plot/11
mkdir worst/plot/12
mkdir worst/plot/13
mkdir worst/plot/14
mkdir worst/plot/15
mkdir worst/plot/16
mkdir worst/plot/17
mkdir worst/plot/18
mkdir worst/plot/19
mkdir worst/plot/20





echo "compliling all component"
make
echo "SUCESSFUL COMPILED"
echo "simulation start"	
./run_list_worst.sh $1 $2 0 $prime1 > worst/plot/1/linkedlist.dat
echo "1st run"	
./run_list_worst.sh $1 $2 0 $prime2 > worst/plot/2/linkedlist.dat	
echo "2nd run"
./run_list_worst.sh $1 $2 0 $prime3 > worst/plot/3/linkedlist.dat
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime4 > worst/plot/4/linkedlist.dat
echo "4rd run"
echo "linked list done"	
./run_heap_worst.sh $1 $2 0 $prime1 > worst/plot/1/heap.dat	
echo "1st run"
./run_heap_worst.sh $1 $2 0 $prime2 > worst/plot/2/heap.dat	
echo "2nd run"
./run_heap_worst.sh $1 $2 0 $prime3 > worst/plot/3/heap.dat
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime4 > worst/plot/4/heap.dat
echo "4rd run"
echo "skew heap done"	
echo "1st data pattern done"




./run_heap_worst.sh $1 $2 0 $prime9 > worst/plot/5/heap.dat	
echo "1st run"
./run_heap_worst.sh $1 $2 0 $prime10 > worst/plot/6/heap.dat
echo "2nd run"	
./run_heap_worst.sh $1 $2 0 $prime11 > worst/plot/7/heap.dat
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime12 > worst/plot/8/heap.dat
echo "4rd run"
echo "skew heap done"	
./run_list_worst.sh $1 $2 0 $prime9 > worst/plot/5/linkedlist.dat
echo "1st run"	
./run_list_worst.sh $1 $2 0 $prime10 > worst/plot/6/linkedlist.dat
echo "2nd run"	
./run_list_worst.sh $1 $2 0 $prime11 > worst/plot/7/linkedlist.dat
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime12 > worst/plot/8/linkedlist.dat
echo "4rd run"
echo "linkedlist done"	
echo "2nd data pattern done"



./run_list_worst.sh $1 $2 0 $prime5 > worst/plot/9/linkedlist.dat
echo "1st run"	
./run_list_worst.sh $1 $2 0 $prime6 > worst/plot/10/linkedlist.dat
echo "2nd run"	
./run_list_worst.sh $1 $2 0 $prime7 > worst/plot/11/linkedlist.dat
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime8 > worst/plot/12/linkedlist.dat
echo "4rd run"
echo "linked list done"
./run_heap_worst.sh $1 $2 0 $prime5 > worst/plot/9/heap.dat
echo "1st run"	
./run_heap_worst.sh $1 $2 0 $prime6 > worst/plot/10/heap.dat
echo "2nd run"	
./run_heap_worst.sh $1 $2 0 $prime7 > worst/plot/11/heap.dat
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime8 > worst/plot/12/heap.dat
echo "4rd run"
echo "skew heap done"			
echo "3rd data pattern done"



echo "5rd run"
echo "linkedlist done"
echo "2nd data pattern done"
./run_list_worst.sh $1 $2 0 $prime13 > worst/plot/13/linkedlist.dat
echo "1st run"
./run_list_worst.sh $1 $2 0 $prime14 > worst/plot/14/linkedlist.dat
echo "2nd run"
./run_list_worst.sh $1 $2 0 $prime15 > worst/plot/15/linkedlist.dat
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime16> worst/plot/16/linkedlist.dat
echo "4rd run"
echo "linked list done"
./run_heap_worst.sh $1 $2 0 $prime13 > worst/plot/13/heap.dat
echo "1st run"
./run_heap_worst.sh $1 $2 0 $prime14 > worst/plot/14/heap.dat
echo "2nd run"
./run_heap_worst.sh $1 $2 0 $prime15 > worst/plot/15/heap.dat
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime16 > worst/plot/16/heap.dat
echo "4rd run"
echo "linkedlist done"
echo "4th data pattern done"



./run_list_worst.sh $1 $2 0 $prime17 > worst/plot/17/linkedlist.dat
echo "1st run"
./run_list_worst.sh $1 $2 0 $prime18 > worst/plot/18/linkedlist.dat
echo "2nd run"
./run_list_worst.sh $1 $2 0 $prime19 > worst/plot/19/linkedlist.dat
echo "3rd run"
./run_list_worst.sh $1 $2 0 $prime20 > worst/plot/20/linkedlist.dat
echo "4rd run"
echo "linked list done"
./run_heap_worst.sh $1 $2 0 $prime17 > worst/plot/17/heap.dat
echo "1st run"
./run_heap_worst.sh $1 $2 0 $prime18 > worst/plot/18/heap.dat
echo "2nd run"
./run_heap_worst.sh $1 $2 0 $prime19 > worst/plot/19/heap.dat
echo "3rd run"
./run_heap_worst.sh $1 $2 0 $prime20 > worst/plot/20/heap.dat
echo "4rd run"
echo "skew heap done"
echo "last data pattern done"
echo "SIMULATION SUECCESSED,PLOTING GRAPH......"




rm enqueue_avg.png
rm dequeue_avg.png

rm enqueue_logscale.png
rm dequeue_logscale.png

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
echo "open graph"
display worst/enqueue_avg.png
display worst/dequeue_avg.png
display worst/enqueue_logscale.png
display worst/dequeue_logscale.png
echo "not crashed!"