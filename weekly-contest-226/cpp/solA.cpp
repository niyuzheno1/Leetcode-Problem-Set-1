#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define X first
#define Y second

#define MAXN 200010
class Solution {
public:
    vector<int> G[MAXN];
    vector<int> ans;
    int visited[MAXN];
    map<int,int> ocur;
    void add(int x, int y){
        x += 100000;
        y += 100000;
        visited[x] = visited[y] = 0;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    void dfs(int x){
        if(visited[x]){
            return;
        }
        ans.push_back(x);
        for(auto & x: G[x]){
            dfs(x);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<vector<int>>& a = adjacentPairs;
        int n = a.size();
        for(int i = 0; i < n;++i){
            add(a[i][0],a[i][1]);
            add(a[i][1],a[i][0]);
            ++ocur[a[i][0]];
            ++ocur[a[i][1]];
        }
        int st = 0;
        for(auto & x: ocur){
            if(ocur[x.X] == 1){
                st = x.X;
                break;
            }
        }
        dfs(st);
        return ans;
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