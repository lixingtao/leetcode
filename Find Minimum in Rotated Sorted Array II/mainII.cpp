#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int findMin(vector<int> &num){
    int pos1,pos2;
    pos1=0;
    pos2=num.size()-1;
    int posmid=0;
    while(num[pos1]>=num[pos2]){
	if(pos1+1==pos2)return num[pos2];

	posmid=(pos2+pos1)>>1;
	if(num[posmid]>num[pos1])
	    pos1=posmid;
	else if(num[posmid]<num[pos1]) pos2=posmid;
	else {
	    int mi=num[pos1];
	    for(int i=pos1+1;i<=pos2;i++){
		if(num[i]<mi)mi=num[i];
	    }
	    return mi;
	}
    }
    return num[posmid];
}
int main(){
    freopen("in.dat","r",stdin);
    vector<int> num;
    int n;
    while(cin>>n)num.push_back(n);
    cout<<findMin(num)<<endl;
    return 0;
}
