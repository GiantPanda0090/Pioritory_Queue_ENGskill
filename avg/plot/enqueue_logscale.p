 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "enqueue_logscale.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The average enqueue pefromence of using skew heap vs linked list as pirority queue (logscale)"

set key left top

set xlabel "Maximum Queue Size"
set ylabel "Time cost (nanosecond)"
set logscale x





data1 = "<( paste avg/plot/enqueue/heap_prob.dat avg/plot/enqueue/heap_mean.dat avg/plot/enqueue/heap_min.dat avg/plot/enqueue/heap_max.dat)"
data2 = "<( paste avg/plot/enqueue/linkedlist_prob.dat avg/plot/enqueue/linkedlist_mean.dat avg/plot/enqueue/list_min.dat avg/plot/enqueue/list_max.dat)"

f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u 1:(column(2)) via a1,b1

f2(x)=a2*x+b2
a2=1
b2=1
fit f2(x) data2 u 1:(column(2)) via a2,b2

plot data1 u 1:(column(2)) w lp pt 6 ps 2 title 'skew heap',data2 u 1:(column(2)) w lp pt 6 ps 2 title 'linked list', data1 u 1:(column(2)):(column(4)):(column(3)) w yerr title 'skew heap error bar' ,data2 u 1:(column(2)):(column(4)):(column(3)) w yerr title 'linked list error bars',f2(x) lc rgb "red" title "linefit for linkedlist",f1(x) lc rgb "red" title "linefit for skew heap" 
