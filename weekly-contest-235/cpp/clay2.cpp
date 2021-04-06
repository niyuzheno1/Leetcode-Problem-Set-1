#define main dummy_main
{}
#undef main

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(), logs.end());
        logs.push_back(vector<int>({-1,-1}));
        vector<int> ans(k);
        int n = logs.size();
        int cuserid = -1, ctime = -1, curcnt = 0;
        rep(i,n){
            if(cuserid != -1 && cuserid != logs[i][0]){
                ++ans[curcnt-1];
                curcnt = 0;
            }
            
            if(cuserid != logs[i][0]){
                cuserid = logs[i][0];
                ctime = -1;
            }
            if(cuserid == -1) break;
            if(ctime != logs[i][1]){
                ++curcnt;
                ctime = logs[i][1];
            }
        }
        return ans;
    }
};