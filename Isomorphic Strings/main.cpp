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

	for (int i = 0; i < lens; i++) {
		if (mp.find(s[i]) != mp.end()) {
			if (mp[s[i]] != t[i]) return false;
		}
		else {
			if (re_mp.find(t[i]) == re_mp.end()) {
				mp[s[i]] = t[i];
				re_mp[t[i]] = s[i];
			}
			else {//if (re_mp.find(t[i]) != re_mp.end() && re_mp[t[i]] != s[i]) {
				return false;
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
