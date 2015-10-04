#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int lenx = matrix.size();
    if (lenx == 0) return false;
    int leny = matrix[0].size();
    if (leny == 0) return false;

    int x = 0, y = leny -1;
    while (x < lenx && y >= 0) {
        int cur = matrix[x][y];
        if (cur == target) return true;
        if (cur > target) y--;
        else x++;
    }
    return false;
}

int main()
{
    return 0;
}
