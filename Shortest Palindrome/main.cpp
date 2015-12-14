#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

string shortestPalindrome(string s) {
	int len = s.size();
	if (!len) return s;

	int l, i;
	const char * str = s.c_str();
	for (l = len; l > 0 ; l--) {
		for (i = 0; i < l/2; i++) if (str[i] != str[l-1-i]) break;
		if (i == l/2) break;
	}

	char add[len-l+1];
	for (i = len-1; i >= l; i--) add[len-1-i] = str[i];
	add[len-l] = 0;

	string tmp = add;
	return tmp + s;
}

int main()
{
	freopen("in.dat", "r", stdin);
	string s;
	while(cin>>s) cout<<shortestPalindrome(s)<<endl;
	return 0;
}
