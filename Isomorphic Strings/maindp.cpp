#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
bool isIsomorphic(string s, string t) {
	int lens = s.length();
	int lent = s.length();
	if (lens != lent) return false;
	map<char, char> mp;
	map<char ,char> re_mp;
	char mp[256];
	char re_mp[256];
	memset(mp, -1, sizeof(mp));
	memset(re_mp, -1, sizeof(re_mp));

	for (int i = 0; i < lens; i++) {
		if (mp[s[i]] != -1) {
			if (mp[s[i]] != t[i]) return false;
		}
		else {
			if (re_mp[t[i]] != -1) return false;
			else {
				re_mp[t[i]] = s[i];
				mp[s[i]] = t[i];
			}
		}
	}
	return true;
}

int main()
{
	string s, t;
	while(cin>>s>>t) {
		cout<<isIsomorphic(s, t)<<endl;
	}
	return 0;
}
