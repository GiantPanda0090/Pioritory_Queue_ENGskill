 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "heap_derivative.png"

set terminal png linewidth 1 size 1920,1080  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The slope of pefromence of using skew heap vs linked list as pirority queue"

set key center left




set xlabel "Number of Applications"
set ylabel "Time cost (nanosecond)"


data1 = "<( paste worst/plot/heap_prob.dat worst/plot/heap_mean.dat worst/plot/heap_min.dat worst/plot/heap_max.dat)"
data2 = "<( paste worst/plot/linkedlist_prob.dat worst/plot/linkedlist_mean.dat worst/plot/list_min.dat worst/plot/list_max.dat)"


set xrange [2000:20000]
delta_v(x) = ( vD = x - old_v, old_v = x, vD)
old_v = NaN

x0=NaN
y0=NaN



f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u 1:(delta_v(column(2))/(delta_v(column(1)))) via a1,b1

f2(x)=a2*x+b2
a2=1
b2=1
fit f2(x) data2 u 1:(delta_v(column(2))/(delta_v(column(1))))  via a2,b2

stat data1 u 1:(delta_v(column(2))/(delta_v(column(1))))
stat data2 u 1:(delta_v(column(2))/(delta_v(column(1))))



plot data1 using 1:(delta_v(column(2))/(delta_v(column(1))))  w lp pt 6 ps 2 title "skew heap", data2 using 1:(delta_v(column(2))/(delta_v(column(1)))) w lp pt 6 ps 2 title "linked list"
