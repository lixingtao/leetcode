#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int len = citations.size();
    int least = 0;
    int pre = -1;
    int i = 0; 
    int h_index = 0;

    while(i < len) {
        least = len - i;
        if (citations[i] >= least && pre <= least) {
            h_index = least;
            break;
        }

        pre = citations[i];
        //while(i<len && citations[i]== citations[i+1]) i++;

        i++;
    }
    return h_index;
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
