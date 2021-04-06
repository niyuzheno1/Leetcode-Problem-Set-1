#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <map>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define to first
#define we second
#define MAXN 2*10010
#define MODN (1000*1000*1000 + 7)
class Solution {
public:
    vector<pii> G[MAXN];
    int dist[MAXN],f[MAXN];

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        for(int i = 1; i <= n; ++i){
            f[i] = 0;
            dist[i] = -1;
        }
        auto chmin = [&](int x, int y){
            if(dist[x] == -1 || dist[x] > y){
                dist[x] = y;
                return true;
            }
            return false;
        };
        for(int i = 0; i < edges.size(); ++i){
            auto  & x = edges[i];
            G[x[0]].push_back(mp(x[1],x[2]));
            G[x[1]].push_back(mp(x[0],x[2]));
        }
        dist[n] = 0;
        queue<int> q;
        q.push(n);
        while(!q.empty()){
            auto u = q.front(); q.pop();
            for(auto & x : G[u])
                if(chmin(x.first, x.second + dist[u]))
                    q.push(x.first);
        }
        vector<pii> a;
        f[1] = 1; 
        for(int i = 1; i <= n; ++i){
            if(dist[i] > dist[1]) continue;
            a.push_back(make_pair(dist[i],i));
        }
        sort(a.begin(), a.end(), greater<pii>());
        int m = a.size();
        for(int i = 0; i < m; ++i){
            auto x = a[i];
            for(auto & y : G[x.second]){
                if(dist[y.first] < dist[x.second]){
                    f[y.first] = (f[y.first] + f[x.second])%MODN;
                }
            }
        }
        return f[n];
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