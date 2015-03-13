#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int hammingWeight(uint32_t n){
	int cnt=0;
	while(n){
		cnt++;
		n=n^(n&-n);
	}
	return cnt;
}

int main()
{
	freopen("in.dat","r",stdin);
	uint32_t n;
	cin>>n;
	cout<<hammingWeight(n)<<endl;
	return 0;
}
