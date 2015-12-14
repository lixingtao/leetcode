#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int maximalSquare(vector<vector<char> >& matrix) {
    int lenx = matrix.size();
    if (!lenx) return 0;
    int leny = matrix[0].size();
    if (!leny) return 0;

    vector<vector<int> >d;

    for (int i = 0; i < lenx; i++) {
        d.push_back(vector<int> ());
        for (int j = 0; j < leny; j++) {
            d[i].push_back(0);
        }
    }

    int ma = 0;
    for (int i = 0; i < lenx; i++) {
        for (int j = 0; j < leny; j++) {
            if ('1' == matrix[i][j]) {
                d[i][j] = 1;
                ma = max(ma, 1);
            }
            if (!i || !j || !d[i][j]) continue;

            /*int candt = d[i-1][j-1];
            int t;
            for (t = 1; t <= candt; t++) {
                if ('1' != matrix[i-t][j] || '1' != matrix[i][j-t]) break;
            }*/
            d[i][j] = min(d[i-1][j], min(d[i][j-1], d[i-1][j-1])) + 1;
            ma = max(ma, d[i][j]);
        }
    }
    return ma*ma;
}

int main()
{
    freopen("in.dat", "r", stdin);
    vector<vector<char> >matrix;
    char s[2];
    int maxy = 5;
    int maxx = 6;
    for (int i = 0; i < maxx; i++) {
        matrix.push_back(vector<char> ());
        for (int j = 0; j < maxy; j++) {
            scanf("%s", s);
            matrix[i].push_back(s[0]);
        }
    }
    cout<<maximalSquare(matrix)<<endl;
    return 0;
}
