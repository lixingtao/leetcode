#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

int stoi(string s){
    int n=0;
    int sign=1;
    int i=0;
    if(s[0]=='-')sign=-1;
    if(s[0]=='-' || s[0]=='+')i++;
    for(;i<s.length();i++)
	n=n*10+s[i]-'0';
    return n*sign;
}

bool isToken(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')return true;
    return false;
}
int evalRPN(vector<string> &tokens){
    stack<int> stk;
    for(int i=0;i<tokens.size();i++){
	char c=tokens[i][0];
	if(isToken(c) && tokens[i].length()==1){
	    int y=stk.top();
	    stk.pop();
	    int x=stk.top();
	    stk.pop();
	    switch(c){
		case '+':
		stk.push(x+y);
		break;
		case '-':
		stk.push(x-y);
		break;
		case '*':
		stk.push(x*y);
		break;
		case '/':
		stk.push(x/y);
	    }
	}
	else stk.push(stoi(tokens[i]));
    }
    return stk.top();
}

int main(){
    freopen("in.dat","r",stdin);
    string s;
    vector<string> ret;
    while(cin>>s)ret.push_back(s);
    cout<<evalRPN(ret)<<endl;
    return 0;
}
