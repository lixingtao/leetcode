#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) nums[cnt++] = nums[i];
    }
    for (; cnt < nums.size(); cnt++) {
        nums[cnt] = 0;
    }
}

void print_vector(vector<int> vet) {
    for (int i = 0; i < vet.size(); i++) {
        cout<<vet[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    freopen("in.dat", "r", stdin);
    int n;
    vector<int> vet;
    while(cin>>n) {
        vet.push_back(n);
    }
    print_vector(vet);
    moveZeroes(vet);
    print_vector(vet);
    return 0;
}
