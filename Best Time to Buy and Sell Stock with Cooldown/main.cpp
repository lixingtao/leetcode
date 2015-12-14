#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const int INF = (1 << 31) - 1;

int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2) return 0;

    int d[len][3];
    d[0][0] = -prices[0];
    d[0][1] = -INF;
    d[0][2] = 0;

    for (int i = 1; i < len; i++) {
        d[i][0] = max(d[i-1][2] - prices[i], d[i-1][0]); //buy
        d[i][1] = d[i-1][0] + prices[i];                //sell
        d[i][2] = max(d[i-1][2], d[i-1][1]);            //cooldown
    }

    return max(max(d[len-1][0], d[len-1][1]), d[len-1][2]);
}

int main()
{
    freopen("in.dat", "r", stdin);
    vector<int> prices;
    int n;
    while(cin>>n) {
        prices.push_back(n);
    }
    cout<<maxProfit(prices)<<endl;
    return 0;
}
