#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

stack<int>stk[2];
int tag = 0;
// Push element x to the back of queue.
void push(int x) {
    stk[tag].push(x);
}

// Removes the element from in front of queue.
void pop(void) {
    if (!stk[1^tag].empty()) {
        stk[1^tag].pop();
        return ;
    }
    while(!stk[tag].empty()) {
        int n = stk[tag].top();
        stk[tag].pop();
        if (stk[tag].empty()) break;
        stk[1^tag].push(n);
    }
}

// Get the front element.
int peek(void) {
    if (!stk[1^tag].empty()) {
        return stk[1^tag].top();
    }
    int n;
    while(!stk[tag].empty()) {
        int t = stk[tag].top();
        stk[tag].pop();
        stk[1^tag].push(t);
        n = t;
    }
    return n;
}

// Return whether the queue is empty.
bool empty(void) {
    if (stk[tag].empty() && stk[1^tag].empty()) return true;
    return false;
}

int main() {
    int n;
    char s[10];
    while(scanf("%s", s) == 1) {
        if (s[0] == 'o') pop(); 
        else if (s[0] == 'i') {
            cin>>n;
            push(n);
        }
        else if (s[0] == 't') cout<<peek()<<endl;
        else if (s[0] == 'e') cout<<empty()<<endl;
    }
    return 0;
}
