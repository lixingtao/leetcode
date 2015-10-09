#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int cmp(const int & a, const int &b) {
    if (a > b) return 1;
    return 0;
}

int minSubArrayLen(int s, vector<int>& nums) {
    
    int cnt = 0;
    int ret = 1 << 30;
    int length = nums.size();
    int l = 0, r = 0;

    for (int i = 0; i < length; i++) {
        cnt += nums[i];
        while(cnt - nums[l] >= s) {
            cnt -=nums[l];
            l++;
        }
        if (cnt >= s) {
            if (i-l+1 < ret) ret = i-l+1;
        }
    }
    if (ret == (1<<30)) return 0;
    return ret;
}

int main()
{
    freopen("in.dat", "r", stdin);
    vector<int> nums;
    int s;
    int n;
    cin>>s;
    while(cin>>n) {
        nums.push_back(n);
    }
    cout<<minSubArrayLen(s, nums)<<endl;
    return 0;
}
