#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
       
        int j = k;
        int ans = 0;
        int curmin = nums[k];
        for(int i = k; i >= 0; --i){
            while( j < n && nums[j] >= curmin) ++ j;
            int nj = j-1;
            curmin = min(curmin,nums[i]);
            ans = max(ans, curmin*(nj-i+1));
        }
        curmin = nums[k];
        j = k;
        for(int i = k; i < n; ++i){
            while( j >=0 && nums[j] >= curmin) -- j;
            int nj = j+1;
            curmin = min(curmin,nums[i]);
            ans = max(ans, curmin * (i-nj+1));
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