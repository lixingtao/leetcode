#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int maxProduct(int A[],int n){
    if(n==0)return 0;
    int ma=A[0];
    int prePos=A[0];
    int preNeg=A[0];
    for(int i=1;i<n;i++){
	int tmpprePos=max(max(prePos*A[i],preNeg*A[i]),A[i]);
	int tmppreNeg=min(min(prePos*A[i],preNeg*A[i]),A[i]);
	prePos=tmpprePos;
	preNeg=tmppreNeg;
	ma=max(ma,prePos);
    }
    return ma;
}

int main(){
    freopen("in.dat","r",stdin);
    const int maxn=1000;
    int A[maxn];
    int n=0;
    while(cin>>A[n])n++;
    cout<<maxProduct(A,n)<<endl;
    return 0;
}
