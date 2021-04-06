#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*e[i] = p[i] xor p[i+1]
e[i+1] xor e[i] = p[i] xor p[i+2]
*/

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}