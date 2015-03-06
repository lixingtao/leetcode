#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int absolutMaxProfit(vector<int> &prices){
    int ret=0;
    for(int i=1;i<prices.size();i++)if(prices[i]>prices[i-1])
	ret+=prices[i]-prices[i-1];
    return ret;
}

int maxProfit(int k,vector<int> &prices){
    if(k<=0)return 0;
    const int NINF=-20000000;
    if(k>prices.size()/2)return absolutMaxProfit(prices);

    int N=k*2+1;

    vector<int> profit(N);
    for(int i=1;i<N;i++)profit[i]=NINF;
    profit[0]=0;

    for(int i=0;i<prices.size();i++){
	for(int j=N-1;j>=1;j--){
	    if(j%2) profit[j]=max(profit[j],profit[j-1]-prices[i]);
	    else profit[j]=max(profit[j],profit[j-1]+prices[i]);
	}
    }

    int ma=0;
    for(int i=0;i<N;i++)ma=max(ma,profit[i]);
    return ma;
}


int main()
{
    freopen("in.dat","r",stdin);
    vector<int> prices;
    int n;
    int k;
    cin>>k;
    char c;
    cin>>c>>c>>c;
    while(cin>>n>>c)prices.push_back(n);
    cout<<maxProfit(k,prices)<<endl;
    return 0;
}
