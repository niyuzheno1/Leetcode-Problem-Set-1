#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    map<int,int> m;
    int findCenter(vector<vector<int>>& edges) {
        for(auto & x : edges){
            ++m[x[0]];
            ++m[x[1]];
            if(m[x[0]] >= 2){
                return x[0];
            }
            if(m[x[1]] >= 2){
                return x[1];
            }
        }
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