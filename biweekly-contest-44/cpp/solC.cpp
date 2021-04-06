#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXN 500
int a[MAXN];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n; cin >>n;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i){
       cout << (a[i]^a[i-1]) << ",";
    }
    return 0;
}