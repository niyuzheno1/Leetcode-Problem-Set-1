#define main dummy_main
{}
#undef main

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(auto x: nums1) s.insert(x);
        int n = nums1.size(), m = nums2.size();
        int diff = 0, idx=0;
        rep(i,m){
            auto k = s.upper_bound(nums2[i]);
            int contri = abs(nums1[i]-nums2[i]);
            if(k == s.begin()){
                diff >?= contri-(*k-nums2[i]);
                if(diff == contri-(*k-nums2[i])){
                    idx = i;
                }
                continue;
            }else{
                if(k != s.end()){
                    diff >?= contri-(*k-nums2[i]);
                    if(diff == contri-(*k-nums2[i])){
                        idx = i;
                    }
                }
                --k;
                diff >?= contri-(nums2[i]-(*k));
                if(diff == contri-(nums2[i]-(*k))){
                    idx = i;
                }
            }
        }
        int ans = -diff;
        rep(i,m){
            ans += abs(nums2[i]-nums1[i]);
            ans %= (1d9+7);
        }
        return ans;
    }
};