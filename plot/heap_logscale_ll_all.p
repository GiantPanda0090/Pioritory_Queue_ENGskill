 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "ll_logscale.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap as pirority queue (logscale)"

set key left top

set xlabel "Number of Applications"
set ylabel "Time cost (nanosecond)"
set logscale x

MAXCOL=20


set xrange[500:20000]




data1 = "<( paste best/plot/*/linkedlist.dat )"
data2 = "<( paste avg/plot/*/linkedlist.dat )"
data3 = "<( paste worst/plot/*/linkedlist.dat)"


plot data2 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) w lp pt 6 ps 2 title "Average Case",data3 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) w lp pt 6 ps 2 title "Worst Case"
