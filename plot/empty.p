 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "empty.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap vs linked list as pirority queue"

set key off

set xlabel "Number of Application"
set ylabel "Time cost"

set xrange [1000:12000]
set yrange [0:5]


data1 = "<( paste plot/*/heap.dat )"
data2 = "<( paste plot/*/linkedlist.dat )"

f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u 1:(($2+$4+$6+$8+$10+$12+$14+$16+$18+$20+$22+$24)/12.0) via a1,b1

f2(x)=a2*x+b2
a2=1
b2=1
fit f2(x) data2 u 1:(($2+$4+$6+$8+$10+$12+$14+$16+$18+$20+$22+$24)/12.0) via a2,b2


plot 10 with lines
