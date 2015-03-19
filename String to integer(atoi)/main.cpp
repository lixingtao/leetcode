#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

bool isWhite(char c){
	if(c==' ' || c=='\n' || c=='\t')
		return true;
	return false;
}

bool isDigit(char c){
	if(c>='0' && c<='9')return true;
	return false;
}

int atoi(string str){
	int p=0;
	int len=str.length();
	while(isWhite(str[p]))p++;
	unsigned int ret=0;
	int sign=1;

	if(str[p]=='+' || str[p]=='-'){
		if(str[p]=='-')sign=-1;
		p++;
	}

	unsigned int MAX=(1<<31);
	if(sign==1)MAX--;

	for(;p<len && isDigit(str[p]) ;p++){
		int add=str[p]-'0';
		if(ret>MAX/10 || ret*10>=MAX-add)
			return (int)(MAX*sign);

		ret=ret*10+add;
	}

	return ret*sign;

}

int main()
{
	freopen("in.dat","r",stdin);
	string str;
	char s[1000];
	while(fgets(s,1000,stdin)){
		str=s;
		cout<<atoi(str)<<endl;
	}
	return 0;
}
