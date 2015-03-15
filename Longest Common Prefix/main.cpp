#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string> &strs){
	if(strs.size()<1)return "";
	int longestPrefix=strs[0].length();
	for(int i=1;i<strs.size();i++){
		int p;
		for(p=0;p<longestPrefix && strs[i][p]==strs[0][p];p++);
		longestPrefix=p;
	}
	return strs[0].substr(0,longestPrefix);
}

int main()
{
	freopen("in.dat","r",stdin);
	vector<string> strs;
	string s;
	while(cin>>s)strs.push_back(s);
	cout<<longestCommonPrefix(strs)<<endl;
	return 0;
}
