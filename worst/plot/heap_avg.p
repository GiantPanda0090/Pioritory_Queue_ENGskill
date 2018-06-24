 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "heap.png"

set terminal png linewidth 1 size 1920,1080  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap vs linked list as pirority queue"

set key left top

set xlabel "Number of Applications"
set ylabel "Time cost (nanosecond)"



MAXCOL = 20


data1 = "<( paste worst/plot/*/heap.dat worst/plot/heap_min.dat worst/plot/heap_max.dat)"
data2 = "<( paste worst/plot/*/linkedlist.dat worst/plot/list_min.dat worst/plot/list_max.dat)"



f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) via a1,b1

f2(x)=a2*x+b2
a2=1
b2=1
fit f2(x) data2 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) via a2,b2




stat data1 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL)
stat data2 u 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL)





plot data1 u 1:41:42 with filledcurves title '95% confidence for skew heap', \
     '' using 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) with lp  pt 6 ps 2 lw 1 title 'skew heap',data2 u 1:41:42 with filledcurves title '95% confidence for linked list', \
     '' using 1:(sum [col=1:MAXCOL] column(col*2))/(MAXCOL) with lp  pt 6 ps 2 lw 1 title 'linked list',f2(x) lc rgb "red" title "linefit for linkedlist",f1(x) lc rgb "red" title "linefit for skew heap"
