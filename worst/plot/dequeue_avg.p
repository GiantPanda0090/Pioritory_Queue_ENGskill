 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "dequeue_avg.png"

set terminal png linewidth 1 size 1920,1080  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap vs linked list as pirority queue"

set key left top

set xlabel "Number of Applications"
set ylabel "Time cost (nanosecond)"



set xrange[1000:20000]

data1 = "<( paste worst/plot/dequeue/heap_prob.dat worst/plot/dequeue/heap_mean.dat worst/plot/dequeue/heap_min.dat worst/plot/dequeue/heap_max.dat)"
data2 = "<( paste worst/plot/dequeue/linkedlist_prob.dat worst/plot/dequeue/linkedlist_mean.dat worst/plot/dequeue/list_min.dat worst/plot/dequeue/list_max.dat)"



f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u 1:2 via a1,b1






stat data1 u 1:2
stat data2 u 1:2





plot data1 u 1:3:4 with filledcurves title '95% confidence for skew heap', \
     '' using 1:2 with lp  pt 6 ps 2 lw 1 title 'skew heap',data2 u 1:3:4 with filledcurves title '95% confidence for linked list', \
     '' using 1:2 with lp  pt 6 ps 2 lw 1 title 'linked list',f1(x) lc rgb "red" title "linefit for skew heap"
