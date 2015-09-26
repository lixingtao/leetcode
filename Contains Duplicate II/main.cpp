#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	map<int, int> index_map;
	for (int i = 0; i < nums.size(); i++) {
		if (index_map.find(nums[i]) != index_map.end()) {
			if (i - index_map[nums[i]] <= k) return true;
		}
		index_map[nums[i]] = i;
	}
	return false;
}

int main()
{
	return 0;
}
