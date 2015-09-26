#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

typedef long long LL;
int countPrimes(int n) {
	vector<int> d(n + 1, 0);
	for (int i = 2; i <= (int)sqrt(n); i++) if (!d[i]) {
		LL tmp = (LL)i << 1;
		while(tmp <= n) {
			d[(int)tmp] = 1;
			tmp += i;
		}
	}

	int count = 0;
	for (int i = 2; i < n; i++) {
		if (!d[i]) count++;
	}
	return count;
}

int main()
{
	int n;
	while(cin>>n) {
		cout<<countPrimes(n)<<endl;
	}
	return 0;
}

