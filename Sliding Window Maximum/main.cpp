#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();
    vector<int> ret;
    if (!len) return ret;

    int left[len], right[len];
    left[0] = nums[0];right[len-1] = nums[len-1];

    for (int i = 1; i < len; i++) {
        if (i % k == 0) left[i] = nums[i];
        else left[i] = max(left[i-1], nums[i]);
    }
    for (int i = len - 2; i >= 0; i--) {
        if (i%k == 0) right[i] = nums[i];
        else right[i] = max(right[i+1], nums[i]);
    }

    for (int i = k-1; i < len; i++) {
        int ma = max(left[i], right[i-k+1]);
        ret.push_back(ma);
    }

    return ret;
}

void print_vet(vector<int> vet) {
    for (int i = 0; i < vet.size(); i++) cout<<vet[i]<<"\t";
    cout<<endl;
}

int main()
{
    freopen("in.dat", "r", stdin);

    int n;
    int k;
    cin>>k;
    vector<int> vet;
    while(cin>>n) {
        vet.push_back(n);
    }
    vector<int> ret = maxSlidingWindow(vet, k);
    print_vet(ret);
    return 0;
}
