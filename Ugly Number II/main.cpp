#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;
const int INF = (1 << 31) - 1;

int Min(LL a, LL b) {
    LL ret = a < b ? a : b;
    return (int)ret;
}

int nthUglyNumber(int n) {
    int d[n+1];
    d[1] = 1;
    int prim[3] = {2, 3, 5};
    for (int i = 2; i <= n; i++) {
        int mi = INF;
        for (int j = 0; j < 3; j++) {
            int t = i - 1;
            while (t > 1 && (LL)d[t-1]*prim[j] > d[i-1]) t--;

            mi = Min(mi, (LL)d[t]*prim[j]);
        }
        d[i] = mi;
    }
    return d[n];
}

int main()
{
    int n;
    while(cin>>n) {
        cout<<nthUglyNumber(n)<<endl;
    }
    return 0;
}
