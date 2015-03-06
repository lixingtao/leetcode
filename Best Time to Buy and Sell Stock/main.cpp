#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int maxProfit(vector<int> &prices){
    if(prices.size()<=1)return 0;
    int mi=prices[0];
    int mostProfit=0;
    
    for(int i=1;i<prices.size();i++){
	mostProfit=max(mostProfit,prices[i]-mi);
	mi=min(mi,prices[i]);
    }
    return mostProfit;
}

int main()
{
    freopen("in.dat","r",stdin);
    vector<int> prices;
    int n;
    while(cin>>n)prices.push_back(n);
    cout<<maxProfit(prices)<<endl;
    return 0;
}
