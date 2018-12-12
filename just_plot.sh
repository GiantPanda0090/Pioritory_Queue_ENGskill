#!/bin/bash
#plot


rm enqueue_avg.png
rm dequeue_avg.png

rm enqueue_logscale.png
rm dequeue_logscale.png

python3 avg/findmaxmin.py

gnuplot avg/plot/enqueue_avg.p
gnuplot avg/plot/dequeue_avg.p

gnuplot avg/plot/enqueue_logscale.p
gnuplot avg/plot/dequeue_logscale.p


rm avg/enqueue_avg.png
rm avg/dequeue_avg.png

rm avg/enqueue_logscale.png
rm avg/dequeue_logscale.png

echo "avg plot done!"
mv enqueue_avg.png avg/enqueue_avg.png
mv dequeue_avg.png avg/dequeue_avg.png
mv enqueue_logscale.png avg/enqueue_logscale.png
mv dequeue_logscale.png avg/dequeue_logscale.png


rm enqueue_avg.png
rm dequeue_avg.png

rm enqueue_logscale.png
rm dequeue_logscale.png

python3 best/findmaxmin.py

gnuplot best/plot/enqueue_avg.p
gnuplot best/plot/dequeue_avg.p

gnuplot best/plot/enqueue_logscale.p
gnuplot best/plot/dequeue_logscale.p

rm best/enqueue_avg.png
rm best/dequeue_avg.png

rm best/enqueue_logscale.png
rm best/dequeue_logscale.png

echo "best plot done!"
mv enqueue_avg.png best/enqueue_avg.png
mv dequeue_avg.png best/dequeue_avg.png
mv enqueue_logscale.png best/enqueue_logscale.png
mv dequeue_logscale.png best/dequeue_logscale.png



rm enqueue_avg.png
rm dequeue_avg.png

rm enqueue_logscale.png
rm dequeue_logscale.png

python3 worst/findmaxmin.py

gnuplot worst/plot/enqueue_avg.p
gnuplot worst/plot/dequeue_avg.p

gnuplot worst/plot/enqueue_logscale.p
gnuplot worst/plot/dequeue_logscale.p

rm worst/enqueue_avg.png
rm worst/dequeue_avg.png

rm worst/enqueue_logscale.png
rm worst/dequeue_logscale.png

echo "worst plot done!"
mv enqueue_avg.png worst/enqueue_avg.png
mv dequeue_avg.png worst/dequeue_avg.png
mv enqueue_logscale.png worst/enqueue_logscale.png
mv dequeue_logscale.png worst/dequeue_logscale.png


gnuplot plot/'heap_logscale.p'
gnuplot plot/'heap_logscale_ll_all.p'
gnuplot plot/'heap_logscale_ll_dequeue_all.p'
gnuplot plot/'heap_logscale_skew_all.p'
gnuplot plot/'heap_logscale_skew_dequeue_all.p'


echo "All plot done!"
