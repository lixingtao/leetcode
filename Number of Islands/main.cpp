#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <iostream>
#include <ctime>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void visit(int spos, int lenx, int leny, vector<vector<char> > &grid, vector<vector<int> > &visited) {
    queue<int> que;
    que.push(spos);
    visited[spos/leny][spos%leny] = 1;

    while(!que.empty()) {
        int pos = que.front();
        que.pop();
        int x = pos / leny;
        int y = pos % leny;
        
        for (int t = 0; t < 4; t++) {
            int newx = x + dx[t];
            int newy = y + dy[t];
            if (newx < lenx && newx >= 0 && newy < leny && newy >=0
                    && !visited[newx][newy] && '1' == grid[newx][newy]) {
                visited[newx][newy] = 1;
                que.push(newx * leny + newy);
            }
        }
    }
}

int numIslands(vector<vector<char> >& grid) {
    int lenx = grid.size();
    if (!lenx) return 0;
    int leny = grid[0].size();
    if (!leny) return 0;

    vector<vector<int> > visited;
    for (int i = 0; i < lenx; i++) {
        vector<int> tmp(leny, 0);
        visited.push_back(tmp);
    }

    int cnt = 0;
    for (int i = 0; i < lenx; i++) {
        for (int j = 0; j < leny; j++) if ('1' == grid[i][j] && !visited[i][j]) {
            visit(i * leny + j, lenx, leny, grid, visited);
            cnt ++;
        }
    }

    return cnt;
}

int main()
{
    freopen("in.dat", "r", stdin);
    char str[1000];
    vector<vector<char> > grid;
    while(scanf("%s", str) == 1) {
        vector<char> tmp;
        for (int i = 0; i < strlen(str); i++) {
            tmp.push_back(str[i]);
        }
        grid.push_back(tmp);
    }
    cout<<numIslands(grid)<<endl;
    return 0;
}
