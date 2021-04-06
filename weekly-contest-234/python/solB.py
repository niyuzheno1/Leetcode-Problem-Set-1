import sys
import argparse


def main():
    n = 496 *2
    a = [i for i in range(n)]
    targ = [i for i in range(n)]
    def step(a):
        arr = [0 for i in range(n)]
        for i in range(n):
            if i % 2 == 0:
                arr[i] = a[i//2]
            else:
                arr[i] = a[n//2+(i-1)//2]
        return arr

    a= step(a)
    if targ == a:
        print(1)
    stp = 1
    while a != targ:
        a = step(a)
        stp = stp + 1
    print(stp)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()