#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int findKth_core(vector<int>& nums, int L ,int R, int k) {
    int l = L;
    int r = R;
    srand((unsigned)time(NULL));

    int rd = rand()%(R-L+1) + L;
    swap(nums[rd], nums[L]);
    int tmp = nums[L];

    while(l < r) {
        while(l < r && nums[r] >= tmp) r--;
        nums[l] = nums[r];
        while(l < r && nums[l] <= tmp) l++;
        nums[r] = nums[l];
    }
    nums[l] = tmp;

    if (l-L+1 == k) return nums[l];
    
    if (l-L+1 < k) return findKth_core(nums, l+1, R, k-(l-L+1));
    else return findKth_core(nums, L, l-1, k);
}

int findKthLargest(vector<int>& nums, int k) {
    return findKth_core(nums, 0, nums.size()-1, nums.size()-k+1);
}


int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    int k = 2;
    cout<<findKthLargest(nums, k)<<endl;
    return 0;
}
