#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int removeDuplicates(int A[],int n){
	int len=0;
	if(n<=0)return 0;

	len=1;
	for(int i=1;i<n;i++)if(A[i]!=A[len-1])
		A[len++]=A[i];
	return len;
}

void print(int *a,int n){
	for(int i=0;i<n;i++)cout<<a[i]<<'\t';
	cout<<endl;
}

int main()
{
	freopen("in.dat","r",stdin);
	int a[100];
	int n=0;
	int t;
	while(cin>>t)a[n++]=t;
	print(a,n);
	n=removeDuplicates(a,n);
	print(a,n);
	return 0;
}
