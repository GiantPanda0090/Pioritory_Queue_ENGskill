#!/usr/bin/python3

import os
import sys
import shutil


def minmax():
    # preperation
    shutil.rmtree('worst/plot/enqueue')
    shutil.rmtree('worst/plot/dequeue')

    os.mkdir('worst/plot/enqueue/')
    os.mkdir('worst/plot/dequeue/')

    os.remove('worst/columns.txt')



    command_list=[]
    command_list.append(('paste worst/plot/*/heap.dat > worst/columns.txt','worst/plot/enqueue/heap_max.dat','worst/plot/enqueue/heap_min.dat','worst/plot/enqueue/heap_mean.dat','worst/plot/enqueue/heap_prob.dat'))
    command_list.append(('paste worst/plot/*/linkedlist.dat > worst/columns.txt','worst/plot/enqueue/list_max.dat','worst/plot/enqueue/list_min.dat','worst/plot/enqueue/linkedlist_mean.dat','worst/plot/enqueue/linkedlist_prob.dat'))

    command_list.append(('paste worst/plot/*/heap.dat > worst/columns.txt','worst/plot/dequeue/heap_max.dat','worst/plot/dequeue/heap_min.dat','worst/plot/dequeue/heap_mean.dat','worst/plot/dequeue/heap_prob.dat'))
    command_list.append(('paste worst/plot/*/linkedlist.dat > worst/columns.txt','worst/plot/dequeue/list_max.dat','worst/plot/dequeue/list_min.dat','worst/plot/dequeue/linkedlist_mean.dat','worst/plot/dequeue/linkedlist_prob.dat'))

    counter =0;
    i=1
    for command,min_path,max_path,mean_path,prob_path in command_list:
        if (counter <2):
            i =1
        else:
            i = 2

        counter+=1

        min_list=[]
        max_list=[]
        mean_list=[]
        x_list=[]


        print('command: '+ command)
        print('min_path: '+ min_path)

        print('max_path: '+ max_path)

        os.system(command)
        with open('worst/columns.txt') as f:
            row=f.readline()

            while row:

                int_perrow = []
                content = [x.strip() for x in row.split()]
                i_queue=i
                while i_queue < len(content):
                    item=content[i_queue]
                    i_queue+=3
                    if item != '':
                        int_perrow.append(float(item))
                answer_tuple=mean_confidence_interval(int_perrow)
                min_list.append(str(answer_tuple[1])+'\n')
                max_list.append(str(answer_tuple[2])+'\n')
                mean_list.append(str(answer_tuple[0])+'\n')
                x_list.append(str(content[0]) + '\n')

                row = f.readline()
        f.close()
        print (str(min_list))
        with open(min_path, 'w+') as f:
            f.writelines(min_list)
            f.close()
        with open(max_path, 'w+') as f:
            f.writelines(max_list)
            f.close()
        with open(mean_path, 'w+') as f:
            f.writelines(mean_list)
            f.close()
        with open(prob_path, 'w+') as f:
            f.writelines(x_list)
            f.close()
    i+=1


    return 'done'

#https://stackoverflow.com/questions/15033511/compute-a-confidence-interval-from-sample-data
import numpy as np
import scipy as sp
import scipy.stats

def mean_confidence_interval(data, confidence=0.95):
    a = 1.0*np.array(data)
    n = len(a)
    m, se = np.mean(a), scipy.stats.sem(a)
    h = se * sp.stats.t._ppf((1-confidence)/2., n-1)
    return m, m-h, m+h


if __name__ == '__main__':
    sys.exit(minmax())
