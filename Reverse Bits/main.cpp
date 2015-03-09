#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

uint32_t reverseBits(uint32_t n){
	uint32_t ret=0;
	uint32_t p=1;
	for(int i=0;i<32;i++){
		ret<<=1;
		if(p & n)ret++;
		p<<=1;
	}
	return ret;
}

int main()
{
	freopen("in.dat","r",stdin);
	uint32_t n;
	cin>>n;
	cout<<reverseBits(n)<<endl;
	return 0;
}
