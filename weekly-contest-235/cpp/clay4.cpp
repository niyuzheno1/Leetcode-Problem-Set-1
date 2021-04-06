#define main dummy_main
{}
#undef main

class Solution {
public:
    int dv[1d5+1];
    int f[2d5+105];
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        dummy_main();
        int n = nums.size();
        int mx = max(nums(n));
        rep(i,mx+2){
            f[i] = 0;
        }
        for(auto x: nums){
            int dsz =Divisor(x,dv);
            rep(i,dsz){
                f[dv[i]] = gcd(x,f[dv[i]]);
            }
        }   
        int cnt = 0;
        rep(i,mx+2){
            if(f[i] == 0) continue;
            if(f[i] == i) ++cnt;
        }
        return cnt;
    }
};