#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define mp make_pair
#define X first
#define Y second
int maxValue(vector<vector<int>>& events, int k) {
    vector<vector<int>> f;
    vector<vector<int>> g;
    
    map<int, int> fx;
    int n = events.size();
    vector<int> s;
    for(auto & x : events){
        s.push_back(x[0]);
        s.push_back(x[1]);
    }
    int tot = 1;
    sort(s.begin(), s.end());
    for(int i = 0; i < s.size(); ++i){
        if(fx[s[i]] == 0){
            fx[s[i]] = tot;
            ++tot;
        }
    }
    vector<vector<pair<int,int>>> e(tot+1); 
    for(int i = 0; i < n; ++i){
        events[i][0] = fx[events[i][0]];
        events[i][1] = fx[events[i][1]];
        e[events[i][1]].push_back(mp(events[i][0], events[i][2]));
    }
    f.resize(tot+1, vector<int>(k+1));
    g.resize(tot+1, vector<int>(k+1));
    int ans = 0;
    for(int i = 1; i <= tot; ++i){
        for(int j = 1; j <= k; ++j){
            if(i > 0){
                g[i][j] = g[i-1][j];
            }
            for(auto & x: e[i])
                f[i][j] = max(g[x.X-1][j-1] + x.Y, f[i][j]);
            g[i][j] = max(f[i][j], g[i][j]);
            ans = max(ans, f[i][j]);
        }

    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n; cin >> n;
    vector<vector<int>> v;
    for(int i = 0; i < n; ++i){
        vector<int> vx;
        for(int j = 0; j < 3; ++j){
            int x; cin >> x;
            vx.push_back(x);
        }
        v.push_back(vx);
    }
    int k; cin >> k;
    maxValue(v,k);
    return 0;
}