#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;


queue<int> qu[2];
int tag = 0;

void push(int x) {
    qu[tag].push(x);
}

// Removes the element on top of the stack.
void pop() {
    while(!qu[tag].empty()) {
        int n = qu[tag].front();
        qu[tag].pop();
        if (qu[tag].empty()) break;
        qu[tag^1].push(n);
    }
    tag = tag ^ 1;
}

// Get the top element.
int top() {
    int n = 0;
    while(!qu[tag].empty()) {
        int t = qu[tag].front();
        qu[tag].pop();
        qu[tag^1].push(t);
        if (qu[tag].empty()) n = t;
    }
    tag = tag ^ 1;
    return n;
}

// Return whether the stack is empty.
bool empty() {
    return qu[tag].empty();
}

int main()
{
    char s[2];
    int n;
    while(scanf("%s", s) == 1) {
        if (s[0] == 'o') pop(); 
        else if (s[0] == 'i') {
            cin>>n;
            push(n);
        }
        else if (s[0] == 't') cout<<top()<<endl;
        else if (s[0] == 'e') cout<<empty()<<endl;
    }
    return 0;
}
