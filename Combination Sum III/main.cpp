#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int used[10];

void dp(vector<vector<int> > &ans, int k, int n, int cur_n, int dep, int min) {
    if (cur_n == n && dep == k) {
        vector<int> tmp;
        for (int i = 1; i <= 9; i++) if (used[i])
            tmp.push_back(i);
        ans.push_back(tmp);
        return ;
    }

    if (cur_n==n || dep==k || min>=10) return ;

    for (int i = min; i <= 9; i++) if (!used[i]) {
        used[i] = 1;
        dp(ans, k, n, cur_n+i, dep+1, i+1);
        used[i] = 0;
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    memset(used, 0, sizeof(used));
    vector<vector<int> > ans;
    dp(ans, k, n, 0, 0, 1);
    return ans;
}

int main()
{
    int k, n;
    while(cin>>k>>n) {
        vector<vector<int> > ans = combinationSum3(k, n);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[0].size(); j++) cout<<ans[i][j]<<"\t";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
