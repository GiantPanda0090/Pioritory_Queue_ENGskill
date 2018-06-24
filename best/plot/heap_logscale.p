 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "heap_logscale.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap vs linked list as pirority queue (logscale)"

set key left top

set xlabel "Number of Applications"
set ylabel "Time cost (nanosecond)"
set logscale xy

MAXCOL=20


set xrange[500:20000]


data1 = "<( paste plot/*/heap.dat )"
data2 = "<( paste plot/*/linkedlist.dat )"

f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) via a1,b1

f2(x)=a2*x+b2
a2=1
b2=1
fit f2(x) data2 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) via a2,b2

plot data1 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) w lp pt 6 ps 2 title "skew heap",data2 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) w lp pt 6 ps 2 title "linked list"
