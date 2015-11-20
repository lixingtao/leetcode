#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int len = nums.size();
    if (1 == len) return nums[0];

    int low = 0, fast = 0;
    do {
        low = nums[low];
        fast = nums[fast];
        fast = nums[fast];
    } while(fast != low);

    low = 0;
    while(low != fast) low = nums[low], fast = nums[fast];

    return low;
}

int main()
{
    vector<int> nums;
    int n;
    freopen("in.dat", "r", stdin);
    while(scanf("%d", &n) == 1) {
        nums.push_back(n);
    };
    cout<<findDuplicate(nums)<<endl;
    return 0;
}

