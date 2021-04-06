#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
#define main dummy_main
int main(){
  return 0;
}
#undef main
class Solution{
  public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2){
    int i;
    set<int> s;
    for(auto x: nums1){
      s.insert(x);
    }
    int n = nums1.size();
    int m = nums2.size();
    int diff = 0;
    int idx=0;
    for(i=(0);i<(m);i++){
      auto k = s.upper_bound(nums2[i]);
      int contri = abs(nums1[i]-nums2[i]);
      if(k == s.begin()){
        chmax(diff, contri-(*k-nums2[i]));
        if(diff == contri-(*k-nums2[i])){
          idx = i;
        }
        continue;
      }
      else{
        if(k != s.end()){
          chmax(diff, contri-(*k-nums2[i]));
          if(diff == contri-(*k-nums2[i])){
            idx = i;
          }
        }
        --k;
        chmax(diff, contri-(nums2[i]-(*k)));
        if(diff == contri-(nums2[i]-(*k))){
          idx = i;
        }
      }
    }
    int ans = -diff;
    for(i=(0);i<(m);i++){
      ans += abs(nums2[i]-nums1[i]);
      ans %= (1000000000+7);
    }
    return ans;
  }
}
;
// cLay version 20210103-1

// --- original code ---
// #define main dummy_main
// {}
// #undef main
// 
// class Solution {
// public:
//     int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
//         set<int> s;
//         for(auto x: nums1) s.insert(x);
//         int n = nums1.size(), m = nums2.size();
//         int diff = 0, idx=0;
//         rep(i,m){
//             auto k = s.upper_bound(nums2[i]);
//             int contri = abs(nums1[i]-nums2[i]);
//             if(k == s.begin()){
//                 diff >?= contri-(*k-nums2[i]);
//                 if(diff == contri-(*k-nums2[i])){
//                     idx = i;
//                 }
//                 continue;
//             }else{
//                 if(k != s.end()){
//                     diff >?= contri-(*k-nums2[i]);
//                     if(diff == contri-(*k-nums2[i])){
//                         idx = i;
//                     }
//                 }
//                 --k;
//                 diff >?= contri-(nums2[i]-(*k));
//                 if(diff == contri-(nums2[i]-(*k))){
//                     idx = i;
//                 }
//             }
//         }
//         int ans = -diff;
//         rep(i,m){
//             ans += abs(nums2[i]-nums1[i]);
//             ans %= (1d9+7);
//         }
//         return ans;
//     }
// };