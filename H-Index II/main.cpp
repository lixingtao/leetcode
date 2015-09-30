#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int judge(vector<int>& citations, int index) {
    if (citations[index] < citations.size() - index) return -1;
    else return 0;
}

int hIndex(vector<int>& citations) {
    int len = citations.size();

    int l = 0; 
    int r = len - 1;

    while(l <= r) {
        int mid = (l+r)>>1;
        int judge_res = judge(citations, mid);
        if (judge_res < 0) l = mid+1;
        else r = mid;
        if (l == r && judge_res >=0) return len - l;
    }
    return 0;
}

int main()
{
    freopen("in.dat", "r", stdin);
    int n;
    vector<int> citations;
    while(cin>>n) {
        citations.push_back(n);
    }
    cout<<hIndex(citations)<<endl;
    return 0;
}
