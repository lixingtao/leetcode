#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

void print_vector(vector<int> d, int len) {
    for (int i = 1; i <= len; i++) printf("%d\t", d[i]);
    cout<<endl;
}

int lower_bound(vector<int> d, int L, int R, int target) {
    int l = L;
    int r = R;
    if (d[R] < target) return R+1;

    while(l < r) {
        if (r-l==1) return d[l] >= target ? l : r;
        if (l==r) return l;

        int m = l + (r-l)/2;
        if (d[m] < target) l = m + 1;
        else r = m;
    }
}

int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    if (!len) return 0;

    vector<int> d(len+1, 0);
    d[1] = nums[0];
    int maxlen = 1;

    for (int i = 1; i < len; i++) {
        int ret = lower_bound(d, 1, maxlen, nums[i]);
        if (ret == maxlen+1) ++maxlen;
        d[ret] = nums[i];
        //print_vector(d, maxlen);
    }
    return maxlen;
}

int main()
{
    int a[] = {1,3,6,7,9,4,10,5,6};
    vector<int> nums(a, a+9);
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}
