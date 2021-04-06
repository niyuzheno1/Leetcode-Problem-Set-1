#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 1010
#define MAXC 27
class Solution {
public:
    int dp[MAXN][MAXN];
    int closest[2][MAXN][MAXC];
    int n1, n2;
    string w1, w2;
    int access(int x, int y, int z){
        if(y == 0)
            return -1;
        return closest[x][y-1][z];
    }
    int compute(){
        for(int i = 0; i <= n1+3; ++i)
            for(int j = 0; j <= n2+3; ++j) 
                dp[i][j] = 0;
        for(int i = 0; i < n1; ++i){
            if(i > 0)
                for(int j = 0; j < MAXC; ++j)
                    closest[0][i][j] = closest[0][i-1][j];
            if(i == 0)
                for(int j = 0; j < MAXC; ++j)
                    closest[0][i][j] = -1;
            closest[0][i][w1[i]-'a'] = i;
        }
        for(int i = 0; i < n2; ++i){
            if(i > 0)
                for(int j = 0; j < MAXC; ++j)
                    closest[1][i][j] = closest[1][i-1][j];
            if(i == 0)
                for(int j = 0; j < MAXC; ++j)
                    closest[1][i][j] = -1;
            closest[1][i][w2[i]-'a'] = i;
        }
        int ans = 0;
        for(int i = 0; i < n1; ++i)
            for(int j = 0; j < n2; ++j){
                if(w1[i] == w2[j]){
                    dp[i][j] = 2;
                    for(int k = 0; k < 26; ++k){
                        if(access(0,i,k) == -1) continue;
                        if(access(1,j,k) == -1) continue;
                        int a =access(0,i,k);
                        int b= access(1,j,k);
                        dp[i][j] = max(dp[i][j], dp[a][b]+2);
                        
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        return ans;
    }
    int longestPalindrome(string word1, string word2) {
        string tmp1,tmp2;
        n1 = word1.length(); n2 = word2.length();
        reverse(word1.begin(), word1.end());
        for(int i = 1; i < n1; ++i) tmp1 += word1[i];
        for(int i = 1; i < n2; ++i) tmp2 += word2[i];
        w1 = word1, w2 = word2;
        int case1 =  compute();
        n1 = tmp1.length();
        w1 = tmp1;
        int case2 = compute()+1;
        n1 = word1.length();
        w1 = word1;
        n2 = tmp2.length();
        w2 = tmp2;
        int case3 = compute()+1;
        if(case2 == 1) case2 = 0;
        if(case3 == 1) case3 = 0;
        return max(max(case1,case2),case3);
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}