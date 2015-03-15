#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool isPalindrome(int x){
	typedef int64_t LL;
	if(x<0)return false;
	LL xl=x;
	LL yl=0;
	while(x){
		yl=yl*10+x%10;
		x/=10;
	}
	return xl==yl;
}

int main()
{
	freopen("in.dat","r",stdin);
	int n;
	while(cin>>n)
		if(isPalindrome(n))cout<<"true"<<endl;
		else cout<<"false"<<endl;
	return 0;
}
