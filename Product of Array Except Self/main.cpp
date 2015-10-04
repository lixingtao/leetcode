#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

/*typedef long long LL;

static int division(LL product, LL y) {
    int tag = 1;
    if (product * y < 0) tag = -1;

    if (product < 0) product = -product;
    if (y < 0) y = -y;
    LL l = 0, r = product;

    while(l < r) {
        LL mid = (l+r)>>1;
        LL tmp = mid * y;
        if (tmp == product) return (int)(mid*tag);
        if (tmp < product) l = mid + 1;
        else r = mid -1;
    }
    return (int)(l * tag);
}

vector<int> productExceptSelf(vector<int>& nums) {
    LL product = 1;
    int zero_tag = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (0 == nums[i]) zero_tag++;
        else product *= nums[i];
    }

    vector<int> d;
    for (int i = 0; i < nums.size(); i++) {
        int tmp;
        if (zero_tag) {
            if (1 == zero_tag && 0 == nums[i]) tmp = (int)product;
            else tmp = 0;
        }
        else {
            tmp = division(product, nums[i]);
        }
        d.push_back(tmp);
    }
    return d;
}*/
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret(nums.size(), 1);
    for (int i = 1; i < ret.size(); i++) {
        ret[i] = ret[i-1] * nums[i-1];
    }
    
    int tmp = 1;
    for (int i = ret.size() - 1; i >= 0; i--) {
        ret[i] = ret[i] * tmp;
        tmp *= nums[i];
    }
    return ret;
}

void print_vet(vector<int> vet) {
    for (int i = 0; i < vet.size(); i++) {
        cout<<vet[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    freopen("in.dat", "r", stdin);
    vector<int> nums;
    int n;
    while(cin>>n) {
        nums.push_back(n);
    }
    print_vet(nums);
    print_vet(productExceptSelf(nums));
    return 0;
}
