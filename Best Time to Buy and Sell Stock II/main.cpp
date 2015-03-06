#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int findMax(vector<int> &prices,int &pos){
    for(;pos<prices.size()-1 && prices[pos]<=prices[pos+1]; pos++);
    return pos;
}

int findMin(vector<int> &prices,int &pos){
    for(;pos<prices.size()-1 && prices[pos]>=prices[pos+1]; pos++);
    return pos;
}

int maxProfit(vector<int> &prices){
    int pos=0;
    int ret=0;
    if(prices.size()<=1)return 0;
    
    while(pos<prices.size()){
	int s=findMin(prices,pos);
	if(s>=prices.size()-1)break;
	pos++;

	int t=findMax(prices,pos);
	pos++;
	ret+=prices[t]-prices[s];
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
