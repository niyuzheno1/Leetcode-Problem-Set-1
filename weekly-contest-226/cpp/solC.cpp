#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ifstream fin1("e1.txt");
    ifstream fin2("e2.txt");
    vector<string> s1,s2;
    while(!fin1.eof()){
        string s; fin1 >>s;
        s1.push_back(s);
    }
    while(!fin2.eof()){
        string s; fin2 >>s;
        s2.push_back(s);
    }
    for(int i = 0; i < s1.size(); ++i)
        if(s1[i] != s2[i]){
            cout << i <<endl;
        }

    return 0;
}