#include <map>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int find_max(int l, int r, vector<int> vet) {
    if (r - l < 0) return 0;
    if(r == l) return vet[l];

    int ppre = vet[l];
    int pre = max(vet[l], vet[l+1]);

    for (int i = l+2; i <= r; i++) {
        int cur = max(vet[i]+ppre, pre);
        ppre = pre;
        pre = cur;
    }

    return pre;
}

int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int a = find_max(0, nums.size() -2, nums);
    int b = find_max(1, nums.size() -1, nums);

    return max(a, b);
}

int main()
{
    freopen("in.dat", "r", stdin);
    int n;
    vector<int> vet;
    while(cin>>n) {
        vet.push_back(n);
    }
    cout<<rob(vet)<<endl;
    return 0;
}
