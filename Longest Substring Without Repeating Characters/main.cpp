#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s){
	int vis[300];
	memset(vis,0,sizeof(vis));

	int len=s.length();
	if(len<=1)return len;

	vis[s[0]]=1;
	int ps=0;
	int pt=1;
	int longest=1;

	for(;pt<len;pt++){
		char c=s[pt];
		while(vis[c])vis[s[ps]]--,ps++;
		vis[c]++;
		longest=max(pt-ps+1,longest);
	}
	return longest;
}

int main()
{
	freopen("in.dat","r",stdin);
	char s[20];
	while(cin>>s)
		cout<<lengthOfLongestSubstring(s)<<endl;
	return 0;
}
