#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define MAXN 100010
typedef pair<double, pair<int,int>> pdi;
#define mp make_pair
#define comput(a,b) (double(a)+1.0)/(double(b)+1.0)-(double(a))/(double(b))
class Solution {
public:
    int cls[MAXN][2];
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pdi> pq;
        int n = classes.size();
        for(int i = 0; i < n; ++i){
            cls[i][0] = classes[i][0]; 
            cls[i][1] = classes[i][1];
            pq.push(mp(comput(cls[i][0],cls[i][1]), mp(i,cls[i][1]))); 
        }
        for(int i = 0; i < extraStudents; ++i){
            auto x = pq.top(); pq.pop();
            int y = x.second.first;
            ++cls[y][0];
            ++cls[y][1];
            pq.push(mp(comput(cls[i][0],cls[i][1]), mp(i,cls[i][1])));
        }
        double ans = 0.0;
        for(int i = 0; i < n; ++i){
            ans += double(cls[i][0])/double(cls[i][1]);
        }
        return ans/double(n);
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