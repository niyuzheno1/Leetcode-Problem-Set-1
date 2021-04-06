#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
class Solution {
public:
    ll divrup(ll x, ll y){
        return (x+(y-1))/y;
    }
    vector<ll> presum;
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        auto n = candiesCount.size();
        auto m = queries.size();
        presum.resize(n);
        //cout << queries[30][0] << " " << queries[30][1] << " " << queries[30][2];
        for(ll i = 0; i < n; ++i){
            if(i > 0){
                presum[i] = presum[i-1];
            }else{
                presum[i] = 0;
            }
            presum[i] += candiesCount[i];
        }
        // cout << presum[43] << endl;
        vector<bool> ans;
        for(ll i = 0; i < m; ++i){
            ll pp = queries[i][0]-1 >= 0? presum[queries[i][0]-1] : 0;
            ll qq = presum[queries[i][0]];
            if(divrup(pp, queries[i][2])-1 <=queries[i][1] && queries[i][1] < qq){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};

ll main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}