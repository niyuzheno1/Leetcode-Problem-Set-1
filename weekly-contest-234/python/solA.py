import sys
import argparse

class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        cur = ""
        ret = {}
        n = len(word)
        for i in range(n):
            if word[i].isnumeric():
                cur += word[i]
            else:
                if cur != "":
                    ret[int(cur)] = 1
                cur = ""
        return len(ret)

def main():
    pass

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()