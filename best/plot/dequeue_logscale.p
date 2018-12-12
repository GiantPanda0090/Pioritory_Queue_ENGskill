 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "dequeue_logscale.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap vs linked list as pirority queue (logscale)"

set key left top

set xlabel "Number of Applications"
set ylabel "Time cost (nanosecond)"
set logscale x



data1 = "<( paste best/plot/dequeue/heap_prob.dat best/plot/dequeue/heap_mean.dat best/plot/dequeue/heap_min.dat best/plot/dequeue/heap_max.dat)"
data2 = "<( paste best/plot/dequeue/linkedlist_prob.dat best/plot/dequeue/linkedlist_mean.dat best/plot/dequeue/list_min.dat best/plot/dequeue/list_max.dat)"

f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u 1:(column(2)) via a1,b1


plot data1 u 1:(column(2)) w lp pt 6 ps 2 title "skew heap",data2 u 1:(column(2)) w lp pt 6 ps 2 title "linked list"