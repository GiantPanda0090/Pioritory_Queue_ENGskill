 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "skew_heap.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set xrange[1000:10000]
set yrange[0:20000]

set title "The pefromence of using skew heap vs linked list as pirority queue"

set key off

set xlabel "Maximum Queue Size"
set ylabel "Time cost (nanosecond)"


plot 0 with lines


