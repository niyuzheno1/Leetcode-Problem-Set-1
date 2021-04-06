#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/*
 [a11, a12, a13]
 [a21, a22, a23]
 [a31, a32, a33]
*/
#define MAXN 1000010
class Solution {
public:
    vector<int> rows;
    vector<int> col;
    vector<int> crows;
    // int a[MAXN];
    // int *enda;
    vector<int> a;
    int pts = 0
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        rows.resize(n, 0);
        crows.resize(n, 0);
        col.resize(n, 0);
        //enda = a;
        a.resize(n*m+10, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                crows[j] = rows[j];
                if(j >= 1){
                    crows[j] ^= col[j-1];
                }
                crows[j] ^= matrix[i][j];
            }
            for(int j = 0; j < n; ++j){
                rows[j] = crows[j];
                *enda = rows[j];
                enda++; 
            }
        }
        --enda;
        sort(a, enda);
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