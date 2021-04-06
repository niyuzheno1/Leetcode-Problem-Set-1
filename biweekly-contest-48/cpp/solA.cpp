#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
#define MAXN 7
class Solution {
public:
    int n;
    vector<int> nums;
    int dp[MAXN][1<<(2*MAXN)];
    vector<int> allpairs;
    vector<pair<int,int>> names;
    int dfs(int x , int state){
        if(x == n/2){
            return 0;
        }
        if(dp[x][state] != -1)  return dp[x][state];
        for(auto x: allpairs){

        }
    }
    int maxScore(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        memset(dp,0xff, sizeof(dp));
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j){
                allpairs.push_back( (1<<i) | (1<<j));
                names.push_back(make_pair(i,j));
            }
        int ans = 0;
        ans = dfs(0, (1 << n)-1);
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}