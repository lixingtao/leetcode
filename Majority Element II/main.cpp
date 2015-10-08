#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

/*int find_kth(vector<int> &nums, int L, int R, int k) {
    if (L >= R) return nums[L];

    int l = L, r = R;
    int tmp = nums[l];

    while(l < r) {
        while(l < r && nums[r] >= tmp) r--;
        nums[l] = nums[r];
        while(l < r && nums[l] <= tmp) l++;
        nums[r] = nums[l];
    }
    nums[r] = tmp;

    int d = l - L + 1;
    
    if (d == k) return nums[l];
    else if (d > k) return find_kth(nums, L, l-1, k);
    else return find_kth(nums, l+1, R, k-d);
}

vector<int> majorityElement(vector<int>& nums) {
    vector<int> ret;
    int len = nums.size();
    if (len == 0) return ret;
    
    int test[3]={0,0,0}, cnt= 0;
    test[0] = find_kth(nums, 0, len-1, len/3-1);
    test[1] = find_kth(nums, 0, len-1, len/3*2-1);
    test[2] = find_kth(nums, 0, len-1, len/3*3-1);
    cnt = 3;

    if (test[0] == test[2]) cnt = 1;
    else if (test[0] == test[1]) cnt = 2, test[1] = test[2];
    else if (test[1] == test[2]) cnt =2;

    int stastic[3] = {0, 0, 0};
    for (int i = 0; i < len ; i++) {
        for (int j = 0; j < cnt ; j++) {
            if (nums[i] == test[j]) stastic[j]++;
        }
    }

    for (int j = 0; j < cnt ; j++)  {
        if (stastic[j] >= len/3) ret.push_back(test[j]);
    }

    return ret;
}*/

int candidate[2];
int cnt[2];


//每三个不同的同时删除
vector<int> majorityElement(vector<int>& nums) {
    vector<int> ret;
    int len  = nums.size();

    cnt[0] = cnt[1] = 0;

    for (int i = 0; i < len; i++) {
        int n = nums[i];
        int found = 0;
        for (int j = 0; j < 2; j++) {
            if (cnt[j] != 0 && candidate[j] == n) {
                cnt[j] ++;
                found = 1;
                break;
            }
        }
        if (!found) 
            for (int j = 0; j < 2; j++) if (cnt[j] == 0) {
                cnt[j] = 1;
                candidate[j] = n;
                found = 1;
                break;
            }
        if (!found) 
            for (int j = 0; j < 2; j++) if (cnt[j]) cnt[j]--;
    }

    int tmp_cnt[2];
    memset(tmp_cnt, 0, sizeof(cnt));
    for (int i = 0; i < len; i++) {
        int n = nums[i];
        for (int j = 0; j < 2; j++) if (cnt[j]) {
            if (candidate[j] == n) tmp_cnt[j]++;
        }
    }
    for (int j = 0; j < 2; j++) if (tmp_cnt[j] > len/3) ret.push_back(candidate[j]);

    return ret;
}

void print_vet(vector<int> vet) {
    for (int i= 0; i < vet.size(); i++) {
        cout<<vet[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    freopen("in.dat", "r", stdin);
    
    int n;
    vector<int> nums;

    while(cin>>n) {
        nums.push_back(n);
    }
    //print_vet(nums);
    print_vet(majorityElement(nums));
    return 0;
}
