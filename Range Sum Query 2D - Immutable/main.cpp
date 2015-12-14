#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        int lenx = matrix.size();
        if (!lenx) return ;
        int leny = matrix[0].size();
        if (!leny) return ;

        sum.push_back(vector<int>());
        sum[0].push_back(matrix[0][0]);
        for (int j = 1; j < leny; j++) sum[0].push_back(matrix[0][j]+sum[0][j-1]);

        for (int i = 1; i < lenx; i++) {
            sum.push_back(vector<int>());
            sum[i].push_back(sum[i-1][0]+matrix[i][0]);
            for (int j = 1; j < leny; j++) {
                sum[i].push_back(matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (0 == row1 && 0 == col1) return sum[row2][col2];
        if (0 == row1) return sum[row2][col2] - sum[row2][col1-1];
        if (0 == col1) return sum[row2][col2] - sum[row1-1][col2];

        return sum[row2][col2] - sum[row2][col1-1] - sum[row1-1] [col2] + sum[row1-1][col1-1];
    }

public:
    vector<vector<int> > sum;
};



int main()
{
    int ni = 5, nj = 5;
    freopen("in.dat", "r", stdin);
    scanf("%d%d", &ni, &nj);
    vector<vector<int> > matrix;
    for (int i = 0; i < ni; i++) {
        matrix.push_back(vector<int>());
        for (int j = 0; j < nj; j++) {
            int n;
            scanf("%d", &n);
            matrix[i].push_back(n);
        }
    }
    NumMatrix sums_obj(matrix);

    cout<<sums_obj.sumRegion(0,0,0,0);
    cout<<endl;
    cout<<sums_obj.sumRegion(0,0,0,1);
    cout<<endl;
    cout<<sums_obj.sumRegion(0,1,0,1);
    cout<<endl;
    return 0;
}
