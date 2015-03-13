#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int reverse(int x){
	int sign=1;
	if(x<0){
		sign=-1,x=-x;
		if(x<0)return 0;
	}

	int ret=0;
	while(x){
		if(ret>INT_MAX/10)return 0;
		if(ret*10>INT_MAX-x%10)return 0;
		ret=ret*10+x%10;
		x/=10;
	}
	return ret*sign;
}

int main()
{
	freopen("in.dat","r",stdin);
	int n;
	while(cin>>n)cout<<reverse(n)<<endl;
	return 0;
}
