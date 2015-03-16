#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s){
	stack<char> stk;
	for(int i=0;i<s.length();i++){
		switch(s[i]){
			case '(': case '[': case '{':
			stk.push(s[i]);
			break;

			case ')':
			if(stk.empty() || stk.top()!='(')return false;
			stk.pop();break;
			
			case ']':
			if(stk.empty() || stk.top()!='[')return false;
			stk.pop();break;

			case '}':
			if(stk.empty() || stk.top()!='{')return false;
			stk.pop();break;
		}
	}
	if(stk.empty())return true;
	return false;
}

int main()
{
	freopen("in.dat","r",stdin);
	string s;
	while(cin>>s)
		if(isValid(s))cout<<"true"<<endl;
		else cout<<"false"<<endl;

	return 0;
}
