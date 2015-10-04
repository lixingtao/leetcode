#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

string itostr(int n) {
    char s[20];
    sprintf(s, "%d", n);
    return s;
}

string get_str(int s, int t) {
    string str;
    if (s == t) str = itostr(s);
    else str = itostr(s) + "->" + itostr(t);
    return str;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    if (nums.size() == 0) return ret;

    int s, t;
    s = t = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (t == nums[i] - 1) t++;
        else {
            ret.push_back(get_str(s, t));
            s = t = nums[i];
        }
    }
    ret.push_back(get_str(s, t));
    return ret;
}

int main()
{
    freopen("in.dat", "r", stdin);
    int n;
    vector<int> vet;
    while(cin>>n) {
        vet.push_back(n);
    }
    vector<string> ret;
    ret = summaryRanges(vet);
    for (int i = 0; i < ret.size(); i++) {
        cout<<ret[i]<<endl;
    }
    return 0;
}
