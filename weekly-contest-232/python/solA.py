import sys
import argparse


def main():
    n = int(input())
    ans = 0
    for i in range(n):
        a,b = list(map(int,input().split()))
        ans += a/b
    print(ans/n)
    return 

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()