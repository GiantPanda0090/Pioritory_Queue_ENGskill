 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "heap.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap vs linked list as pirority queue"

set key left top

set xlabel "Element"
set ylabel "Operation"

set xrange [1000:12000]


data1 = "<( paste plot/*/heap.dat )"
data2 = "<( paste plot/*/linkedlist.dat )"

f1(x)=a1*x+b1
a1=1
b1=1


f2(x)=60*log(x)




plot f1(x) lc rgb "red" title "O(N)",f2(x) lc rgb "blue" title "O(LOG N)"
