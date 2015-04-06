#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

int rob(vector<int> &num){
	if(num.size()==0)return 0;
	if(num.size()==1)return num[0];
	if(num.size()==2)return max(num[0],num[1]);

	int pre=max(num[0],num[1]);
	int ppre=num[0];
	int cur;
	for(int i=2;i<num.size();i++){
		cur=max(pre,ppre+num[i]);
		ppre=pre;
		pre=cur;
	}

	return cur;
}

int main()
{
	freopen("in.dat","r",stdin);
	vector<int> num;
	int n;
	while(scanf("%d",&n)==1)
		num.push_back(n);
	printf("%d\n",rob(num));
	return 0;
}
