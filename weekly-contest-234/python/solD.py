import sys
import argparse

def proc(n):
    m = (n//3)
    if n % 3 == 0:
        return pow(3,m, 10**9+7)
    elif n % 3 == 1:
        return 4*pow(3,m-1, 10**9+7)
    else:
        return 2*pow(3,m, 10**9+7)
    

def main():
    m = 8
    print(proc(m))
    for i in range(1,m):
        dst = m//i
        a = [dst for j in range(0,i)]
        sum(a)
        n = m%i
        for j in  range(0,n):
            a[j] = a[j]+1
        k = 1 
        for j in range(0,i):
            k *= a[j]
        print(k)
#6,9,12,18

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()