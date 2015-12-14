#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	int len = nums.size();
	if (!len) return 0;

	set<int> st;
	for (int i = 0; i < len; i++) {
		if (i > k) st.erase(nums[i-k-1]);
		set<int>::iterator it = st.lower_bound(nums[i] - t);
		if (it!=st.end() && *it-nums[i]<=t) return 1;

		st.insert(nums[i]);
	}
	return 0;
}

int main()
{
	return 0;
}
