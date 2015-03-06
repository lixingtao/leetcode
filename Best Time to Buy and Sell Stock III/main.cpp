#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
int maxProfit(vector<int> &prices){
    if(prices.size()<=1)return 0;
    vector<int> leftProfit(prices.size());
    int leftMaxProfit=0;
    int mi=prices[0];
    for(int i=1;i<prices.size();i++){
	leftProfit[i]=max(prices[i]-mi,leftProfit[i-1]);
	mi=min(mi,prices[i]);
    }

    int rightMaxProfit=0;
    int ma=prices[prices.size()-1];
    int ret=0;
    for(int i=prices.size()-2;i>=0;i--){
	rightMaxProfit=max(rightMaxProfit,ma-prices[i]);
	if(i>=1)ret=max(ret,rightMaxProfit+leftProfit[i-1]);
	else ret=max(ret,rightMaxProfit);
	ma=max(ma,prices[i]);
    }
    return ret;
}

int main()
{
    freopen("in.dat","r",stdin);
    vector<int> prices;
    int n;
    while(cin>>n){
	prices.push_back(n);
    }
    cout<<maxProfit(prices)<<endl;
    return 0;
}
