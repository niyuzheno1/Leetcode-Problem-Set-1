#define main dummy_main
{}
#undef main

class Solution {
public:
    string truncateSentence(string s, int k) {
        s += " ";
        int n = s.length();
        string ans;
        int sp = 0;
        rep(i,0,n){
            if(s[i] == ' '){
                ++sp;
            }
            if(sp == k) break;
            ans += s[i];
        }
        return ans;
    }
};