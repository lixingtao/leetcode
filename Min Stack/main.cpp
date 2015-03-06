#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

stack<int> stk;
stack<int> mi;

void push(int x){
    stk.push(x);
    if(mi.empty())mi.push(x);
    else if(mi.top()>=x)mi.push(x);
}

void pop(){
    int x=stk.top();
    if(!stk.empty())stk.pop();
    if(!mi.empty() && mi.top()==x)mi.pop();
}

int top(){
    if(!stk.empty())return stk.top();
    return -1;
}

int getMin(){
    if(!mi.empty())return mi.top();
    return -1;
}

int main(){
    return 0;
}
