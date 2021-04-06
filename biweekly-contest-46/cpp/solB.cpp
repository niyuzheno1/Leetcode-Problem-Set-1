#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
#define MAXN 100010
#define MAXV 51
class Solution {
public:
    int f[MAXN][MAXV];
    int dep[MAXN];
    vector<int> & nums;
    vector<int> G[MAXN];
    void dfs(int x, int p){
        f[x][nums[x]] = x;
        for(auto & u : G[x]){
            if(u == p) continue;
            for(int j = 0; j <= 50; ++j){
                f[u][j] = f[x][j];
            }
            dep[u] = dep[x]+1;
            dfs(u,x);
        }
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        for(auto & e : edges){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        for(int i = 0; i <= 50; ++i) f[0][i] = -1;
        dep[0] = 1;
        dfs(0,-1);
        vector<int> ansx;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int ans = -1;
            for(int j = 0; j <= 50; ++j){
                if(f[i][j] == -1) continue;
                if(gcd(j, nums[i]) != 1) continue;
                if(ans == -1){
                    ans = f[i][j];
                }
                if(dep[ans] < dep[f[i][j]])
                    ans = f[i][j];
            }
            ansx.push_back(ans);
        }
        return ansx;
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