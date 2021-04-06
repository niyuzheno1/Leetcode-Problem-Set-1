import sys
import argparse

class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        A = { x[0] : x[1] for x in knowledge}
        ans = ""
        inbracket = False
        cur = ""
        n = len(s)
        for i in range(n):
            if s[i] == '(':
                inbracket = True
            elif s[i] == ')':
                if cur in A:
                    ans += A[cur]
                else:
                    ans += "?"
                inbracket = False
                cur = ""
            elif inbracket == True:
                cur += s[i]
            else:
                ans += s[i]
        return ans
def main():
    pass

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()