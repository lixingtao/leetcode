#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 10010;
const int maxe = 100010;

int first[maxn];
int U[maxe], V[maxe], next[maxe];
int edge = 0;

int visited[maxn];

void addE(int x, int y) {
    U[edge] = x;
    V[edge] = y;
    next[edge] = first[x];
    first[x] = edge;
    edge++;
}

int visit(int x) {
    visited[x] = 1;
    int ret = 1;
    for (int e = first[x]; e != -1; e = next[e]) {
        if (visited[V[e]]) return 0;
        ret = visit(V[e]);
        if (!ret) return 0;
    }
    return 1;
}

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    memset(first, -1, sizeof(first));
    edge = 0;
    memset(visited, 0, sizeof(visited));

    for (vector<pair<int, int> >::iterator it = prerequisites.begin(); it != prerequisites.end(); it++) {
        int s = it->first;
        int t = it->second;
        addE(t, s);
    }

    for (int i = 0; i < numCourses; i++) {
        memset(visited, 0, sizeof(visited));
        if (!visit(i)) return 0;
    }

    return 1;
}

int main()
{
    vector<pair<int, int> > prerequisites;
    pair<int, int> pa(1, 0);
    prerequisites.push_back(pa);
    int nums = 2;
    cout<<canFinish(nums, prerequisites)<<endl;
    return 0;
}
