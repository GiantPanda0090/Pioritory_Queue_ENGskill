 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "skewheap_logscale.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The Enqueue pefromence of using skew heap as pirority queue (logscale)"

set key left top

set xlabel "Maximum Queue Size"
set ylabel "Time cost (nanosecond)"
set logscale x




data1 = "<( paste best/plot/enqueue/heap_prob.dat best/plot/enqueue/heap_mean.dat )"
data2 = "<( paste avg/plot/enqueue/heap_prob.dat avg/plot/enqueue/heap_mean.dat avg/plot/enqueue/heap_min.dat avg/plot/enqueue/heap_max.dat)"
data3 = "<( paste worst/plot/enqueue/heap_prob.dat worst/plot/enqueue/heap_mean.dat worst/plot/enqueue/heap_min.dat worst/plot/enqueue/heap_max.dat)"

f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data2 u 1:(column(2)) via a1,b1

f2(x)=a2*x+b2
a2=1
b2=1
fit f2(x) data3 u 1:(column(2)) via a2,b2


plot data2 u 1:(column(2)) with lp  pt 6 ps 2 lw 1 title 'Average Case',data3 u 1:(column(2)) with lp  pt 6 ps 2 lw 1 title 'Worst Case',f2(x) lc rgb "green" title "linefit for Average Case",f1(x) lc rgb "red" title "linefit for Worst Case", data2 u 1:(column(2)):((column(3)-column(2))) w yerr title 'Worst Case error bar',data3 u 1:(column(2)):((column(3)-column(2))) w yerr title 'Average Case error bars'
