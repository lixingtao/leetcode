#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
const int INF=(1<<31)-1;

int maximumGap(vector<int> &num){
    if(num.size()<2)return 0;
    double mi=INF;
    double ma=-INF;
    vector<int> bucketma(num.size(),-INF);
    vector<int> bucketmi(num.size(),INF);

    for(int i=0;i<num.size();i++){
	if(mi>num[i])mi=num[i];
	if(ma<num[i])ma=num[i];
    }
    double width=(ma+1-mi)/num.size();
    
    for(int i=0;i<num.size();i++){
	int pos=(int)(num[i]-mi)/width;
	bucketma[pos]=max(bucketma[pos],num[i]);
	bucketmi[pos]=min(bucketmi[pos],num[i]);
    }
    
    int ans=0;
    int pos=0;
    while(pos<num.size() && bucketma[pos]<0)pos++;
    int posnum=bucketma[pos];
    for(int i=pos+1;i<num.size();i++){
	if(bucketma[i]>=0){
	    ans=max(ans,bucketmi[i]-posnum);
	    posnum=bucketma[i];
	}
    }
    return ans;
}
int main(){
    freopen("in.dat","r",stdin);
    vector<int> num;
    int n;
    while(cin>>n)num.push_back(n);
    cout<<maximumGap(num)<<endl;
    return 0;
}
