 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "heap.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color 
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap as pirority queue"

set key left top
    
set xlabel "Number of Application"
set ylabel "Time cost"    

set xrange [1:10000]
set yrange [0.002:0.007]

data = "<( paste */heap.dat )"
stat data
plot data u 1:(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0) w lp pt 6 ps 2
