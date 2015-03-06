#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rotate(int num[],int n,int k){
    if(k<=0)return ;
    k=k%n;

    for(int i=0;i<n/2;i++)swap(num[i],num[n-1-i]);

    for(int i=0;i<k/2;i++)swap(num[i],num[k-1-i]);
    for(int i=k;i<k+(n-k)/2;i++)swap(num[i],num[n-1-(i-k)]);
}

void printVector(int num[],int n){
    for(int i=0;i<n;i++)cout<<num[i]<<'\t';
    cout<<endl;
}

int main()
{
    freopen("in.dat","r",stdin);
    int num[1000];
    int n,k;
    n=0;
    cin>>k;
    while(cin>>num[n])n++;
    
    printVector(num,n);
    rotate(num,n,k);
    printVector(num,n);

    return 0;
}
