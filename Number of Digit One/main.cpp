#include <map>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int countDigitOne(int n) {
    int mod  =1;
    int cur, high, low;
    int cnt = 0;
    while(n/mod) {
        low = n % mod;
        cur = n / mod % 10;
        high = n / mod / 10;
        if (cur > 1) cnt += (high+1) * mod;
        else if (1 == cur) cnt += high * mod + low + 1;
        else cnt += high * mod;

        if (mod > ((1<<31) -1)/10) break;
        mod *= 10;
    }
    return cnt;
}

int main()
{
    int n;
    while(cin>>n) {
        cout<<countDigitOne(n)<<endl;
    }
    return 0;
}
