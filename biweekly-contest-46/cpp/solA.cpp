#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
#define MAXN 1010
typedef pair<int,int> pii;
typedef pair<int, pii> pti;
#define X second.first
#define Y second.second
#define val first
#define mp make_pair
const int dx[] =  {1,-1,0,0};
const int dy[] = {0,0,1,-1};
class Solution {
public:
    int ans[MAXN][MAXN];
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        priority_queue<pti> pq;
        int n = isWater.size();
        int m = isWater[0].size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                ans[i+1][j+1] = INT_MAX;
                if(isWater[i][j] == 1){
                    ans[i+1][j+1] = 0;
                    pq.push(mp(0,mp(i+1,j+1)));
                }
            }
        for(int i = 0; i <= n+1; ++i)
            for(int j = 0; j <= m+1; ++j)
                if(i == 0 || j == 0 || i == n+1 || j == m+1) ans[i][j] = 0;
        while(!pq.empty()){
            auto & x = pq.top(); pq.pop();
            if(-x.val > ans[x.X][x.Y]) continue;
            for(int i = 0; i < 4; ++i){
                int nx = x.X + dx[i];
                int ny = x.Y + dy[i];
                if(ans[x.X][x.Y] + 1 < ans[nx][ny]){
                    ans[nx][ny] = ans[x.X][x.Y] + 1;
                    pq.push(mp(-ans[nx][ny],mp(nx,ny)));
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 1, vector<int> tmp; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                tmp.push_back(ans[i][j]);
            }
            ans.push_back(tmp);
        }
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