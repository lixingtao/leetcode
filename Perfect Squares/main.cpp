#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

const double small = 1e-9;

int get_max_squares(int n) {
    double square = sqrt(n) + small;
    return (int)square;
}

int numSquares(int n) {
    if (n <= 0) return 0;

    int square = get_max_squares(n);

    if (square*square == n) return 1;

    while((n & 3) == 0) {
        n = n >> 2;
    }
    if ((n & 7) == 7) return 4;

    for (int i = 1; i <= square; i++) {
        int t = n - i*i;
        int tmp_sq = get_max_squares(t);
        if (tmp_sq * tmp_sq == t) return 2;
    }

    return 3;
}

int main()
{
    int n;
    while(cin>>n) {
        cout<<numSquares(n)<<endl;
    }
    return 0;
}
