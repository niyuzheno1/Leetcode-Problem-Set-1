#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T> int Factor_L(T N, T fac[], int fs[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    fs[sz] = 1;
    N /= 2;
    while(N%2==0){
      N /= 2;
      fs[sz]++;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      fs[sz] = 1;
      N /= i;
      while(N%i==0){
        N /= i;
        fs[sz]++;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    fs[sz] = 1;
    sz++;
  }
  return sz;
}
template<class T> int Divisor_L(T N, T res[], void *mem = wmem){
  int i;
  int j;
  int k;
  int s;
  int sz = 0;
  T*fc;
  int*fs;
  int fsz;
  walloc1d(&fc, 100, &mem);
  walloc1d(&fs, 100, &mem);
  fsz =Factor_L(N, fc, fs);
  res[sz++] = 1;
  for(i=(0);i<(fsz);i++){
    s = sz;
    k = s * fs[i];
    for(j=(0);j<(k);j++){
      res[sz++] = res[j] * fc[i];
    }
  }
  sort(res, res+sz);
  return sz;
}
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
#define main dummy_main
int main(){
  wmem = memarr;
  return 0;
}
#undef main
class Solution{
  public:
  int dv[100000+1];
  int f[200000+105];
  int countDifferentSubsequenceGCDs(vector<int>& nums){
    int i;
    dummy_main();
    int n = nums.size();
    int Lj4PdHRW;
    int KL2GvlyY;
    if(n==0){
      KL2GvlyY = 0;
    }
    else{
      KL2GvlyY = nums[0];
      for(Lj4PdHRW=(1);Lj4PdHRW<(n);Lj4PdHRW++){
        KL2GvlyY = max_L(KL2GvlyY, nums[Lj4PdHRW]);
      }
    }
    int mx = KL2GvlyY;
    for(i=(0);i<(mx+2);i++){
      f[i] = 0;
    }
    for(auto x: nums){
      int dsz =Divisor_L(x,dv);
      for(i=(0);i<(dsz);i++){
        f[dv[i]] =GCD_L(x, f[dv[i]]);
      }
    }
    int cnt = 0;
    for(i=(0);i<(mx+2);i++){
      if(f[i] == 0){
        continue;
      }
      if(f[i] == i){
        ++cnt;
      }
    }
    return cnt;
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
//     int dv[1d5+1];
//     int f[2d5+105];
//     int countDifferentSubsequenceGCDs(vector<int>& nums) {
//         dummy_main();
//         int n = nums.size();
//         int mx = max(nums(n));
//         rep(i,mx+2){
//             f[i] = 0;
//         }
//         for(auto x: nums){
//             int dsz =Divisor(x,dv);
//             rep(i,dsz){
//                 f[dv[i]] = gcd(x,f[dv[i]]);
//             }
//         }   
//         int cnt = 0;
//         rep(i,mx+2){
//             if(f[i] == 0) continue;
//             if(f[i] == i) ++cnt;
//         }
//         return cnt;
//     }
// };