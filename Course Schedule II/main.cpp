#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 1001;
const int maxe = 10010;

int U[maxe], V[maxe], next[maxe];
int first[maxn];
int edge = 0;

void addE(int x, int y) {
    U[edge] = x;
    V[edge] = y;
    next[edge] = first[x];
    first[x] = edge;
    edge++;
}

int dfs(vector<int> & visited, vector<int> &topo, int u) {
    visited[u] = -1;

    for (int e = first[u]; e != -1; e = next[e]) {
        int v = V[e];
        if (visited[v] < 0) return 0;
        else if (!visited[v] && !dfs(visited, topo, v)) return 0;
    }

    visited[u] = 1;
    topo.push_back(u);

    return 1;
}

vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<int> topo;
    if (numCourses <= 0) return topo;
    if (prerequisites.size() == 0) {
        for (int i = 0; i < numCourses; i++) topo.push_back(i);
        return topo;
    }

    memset(first, -1, sizeof(first));
    edge = 0;

    for (vector<pair<int, int> >::iterator it = prerequisites.begin(); it != prerequisites.end(); it++) {
        //cout<<"first: "<<it->first<<" second: "<<it->second<<endl; //*******
        addE(it->second, it->first);
    }

    vector<int> visited(numCourses, 0);
    for (int i = 0; i < numCourses; i++) if (!visited[i]) {
        //cout<<"i: "<<i<<endl;
        if (!dfs(visited, topo, i)) {
            return vector<int> ();
        }
    }
    int len = topo.size();
    for (int i = 0; i < len/2; i++) swap(topo[i], topo[len-1-i]);

    return topo;
}

int main()
{
    freopen("in.dat", "r", stdin);
    int n;
    vector<pair<int, int > >prereq;
    cin>>n;
    int a, b;
    while(cin>>a>>b) {
        pair<int, int> tmp(a, b);
        prereq.push_back(tmp);
    }
    vector<int> ret = findOrder(n, prereq);
    for (int i = 0; i < ret.size(); i++) {
        cout<<ret[i]<<endl;
    }
    cout<<endl;
    return 0;
}
