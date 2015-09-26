#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <iostream>

using namespace std;

typedef long long LL;

bool isHappy(int n) {
	set<int> st;
	while(1) {
		int n_dump = n;
		int cur = 0;
		while(n_dump) {
			int sg = n_dump % 10;
			n_dump /= 10;
			cur += sg * sg;
		}
		if (cur == 1) return 1;
		if (st.find(cur) != st.end())return 0;
		cout<<cur<<endl;
		n = cur;
		st.insert(cur);
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) ==1) {
		if (isHappy(n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
