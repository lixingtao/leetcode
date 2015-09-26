#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    map<int, bool> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) != mp.end()) return true;
        else mp[nums[i]] = 1;
    }
    return false;
}

int main()
{
    return 0;
}
