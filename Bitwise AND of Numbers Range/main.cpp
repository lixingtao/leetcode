#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*int rangeBitwiseAnd(int m, int n) {
    int t = m;
    int ret = 0;

    while(t) {
        int low_bit = t & (-t);
        t = t & (t-1);

        int resid = m % low_bit;
        if (low_bit-resid > n-m) ret += low_bit;
    }
    return ret;
}*/
int rangeBitwiseAnd(int m, int n) {
    int i;
    for(i=0;m!=n;m>>=1,n>>=1)i++;
    return m<<i;
}

int main()
{
    int m, n;
    while(cin>>m>>n) {
        cout<<rangeBitwiseAnd(m, n)<<endl;
    }
    return 0;
}
