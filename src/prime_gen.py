# Sieve of Eratosthenes
# Code by David Eppstein, UC Irvine, 28 Feb 2002
# http://code.activestate.com/recipes/117119/

import sys
import random

def gen_primes(max):
    """ Generate an infinite sequence of prime numbers.
    """
    # Maps composites to primes witnessing their compositeness.
    # This is memory efficient, as the sieve is not "run forward"
    # indefinitely, but only as long as required by the current
    # number being tested.
    #
    D = {}

    # The running integer that's checked for primeness
    q = 2

    while q < max:
        if q not in D:
            # q is a new prime.
            # Yield it and mark its first multiple that isn't
            # already marked in previous iterations
            #
            yield q
            D[q * q] = [q]
        else:
            # q is composite. D[q] is the list of primes that
            # divide it. Since we've reached q, we no longer
            # need it in the map, but we'll mark the next
            # multiples of its witnesses to prepare for larger
            # numbers
            #
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]

        q += 1


def main():
    max=sys.argv[1]
    lst=[]
    if len(sys.argv) == 4:
        import_path=sys.argv[2]
        counter=sys.argv[3]

        import_file= open(import_path,"r")
        for prime in import_file:
            lst.append(int(prime))
        out = lst[int(counter)-1]
    else:
        prime_generator = gen_primes(int(max))
        lst=list(prime_generator)
        out = lst[random.randint(1, len(lst)) - 1]
    print(out)
    return int(out)


if __name__ == '__main__':
    sys.exit(main())
