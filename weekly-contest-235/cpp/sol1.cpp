#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define main dummy_main
int main(){
  return 0;
}
#undef main
class Solution{
  public:
  string truncateSentence(string s, int k){
    int i;
    s += " ";
    int n = s.length();
    string ans;
    int sp = 0;
    for(i=(0);i<(n);i++){
      if(s[i] == ' '){
        ++sp;
      }
      if(sp == k){
        break;
      }
      ans += s[i];
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
//     string truncateSentence(string s, int k) {
//         s += " ";
//         int n = s.length();
//         string ans;
//         int sp = 0;
//         rep(i,0,n){
//             if(s[i] == ' '){
//                 ++sp;
//             }
//             if(sp == k) break;
//             ans += s[i];
//         }
//         return ans;
//     }
// };