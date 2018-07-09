//
// Created by lqschool on 2018-06-30.
//

#include "print_ascii.h"


//reference :https://forgetcode.com/c/385-generating-n-prime-numbers
int generate_prime(int n) {
    int  i = 3, count, c;
    int prime=0;



    if (n >= 1) {
        //printf("First %d prime numbers are :\n", n);
        //printf("2\n");
    }

    for (count = 2; count <= n;) {
        for (c = 2; c <= i - 1; c++) {
            if (i % c == 0)
                break;
        }
        if (c == i) {
            //printf("%d\n", i);
            prime=i;
            count++;
        }
        i++;
    }

    return prime;
}
