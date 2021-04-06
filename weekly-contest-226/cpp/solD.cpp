#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MODN 1299833
typedef long long ll;
class Solution {
public:
    vector<int> p;
    vector<int> pre;
    vector<int> pos;
    int n;
    int sub(int x, int y){
        return (x-y + MODN) %MODN;
    }
    int getpre(int l, int r){
        int plm = l > 0 ? pre[l-1] : 0;
        return sub(pre[r],(plm*p[r-l+1])%MODN);
    }
    int getpos(int l, int r){
        int plm = r < n-1? pos[r+1] : 0;
        return sub(pos[l],(plm*p[r-l+1])%MODN);
    }
    bool checkPartitioning(string s) {
        p.resize(2010);
        n = s.size();
        pre.resize(n);
        pos.resize(n);
        p[0] = 1;
        int mul = 28;
        for(int i = 1; i < p.size(); ++i){
            p[i] = p[i-1];
            p[i] = p[i] * mul;
            p[i] %= MODN;
        }
        for(int i = 0; i < n; ++i){
            int u = s[i]-'a'+1;
            if(i > 0){
                pre[i] = pre[i-1]* mul;
                pre[i] %= MODN;
            }
            pre[i] = pre[i] + u;
            pre[i] = pre[i] % MODN;
        }
        for(int i = n-1; i >= 0; --i){
            int u = s[i]-'a'+1;
            if(i < n-1){
                pos[i] = pos[i+1]* mul;
                pos[i] %= MODN;
            }
            pos[i] = pos[i] + u;
            pos[i] = pos[i] % MODN;
        }
        for(int i = 0; i < n; ++i){
            for(int j = n-1; j > i; --j){
                
            }
        }
    }
};

// long exponentiation(ll base, long exp) 
// { 
//     long t = 1L; 
//     while (exp > 0)  
//     { 
  
//         // for cases where exponent 
//         // is not an even value 
//         if (exp % 2 != 0) 
//             t = (t * base) % N; 
  
//         base = (base * base) % N; 
//         exp /= 2; 
//     } 
//     return t % N; 
// } 

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}