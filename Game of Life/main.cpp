#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void gameOfLife(vector<vector<int> >& board) {
    int n = board.size();
    if (!n) return ;
    int m = board[0].size();
    if (!m) return ;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x<n && x>=0 && y<m && y>=0 && board[x][y] % 10) 
                    cnt++;
            }
            if (board[i][j] % 10) {
                if (2==cnt || 3==cnt) board[i][j] += 10;
            }
            else {
                if (3 == cnt) board[i][j] += 10;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) board[i][j] = board[i][j] / 10;
    }
}

void print_vvet(vector<vector<int> > vvet) {
    for (int i= 0; i < vvet.size(); i++) {
        for (int j = 0; j < vvet[i].size(); j++) {
            cout<<vvet[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    vector<vector<int> >board(2);
    board[0].push_back(1);
    board[0].push_back(1);
    board[1].push_back(1);
    board[1].push_back(0);
    print_vvet(board);
    gameOfLife(board);
    print_vvet(board);
    return 0;
}
