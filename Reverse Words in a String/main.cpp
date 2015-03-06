#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

void reverse(string &str,int s,int t){
    for(int i=s;i<= (s+t)>>1;i++)
	swap(str[i],str[t-(i-s)]);
}

bool isEmpty(char c){
    if(c==' ' || c=='\t' || c=='\n' || c=='\0')
	return true;
    return false;
}
void skip(string &str,int &index){
    while(isEmpty(str[index]))
	index++;
}
void reverseWords(string &s){
    int pos=0;
    int i=0;
    skip(s,i);
    if(i>=s.length()){
	s="";
	return ;
    }
    while(i<=s.length()){
	if(isEmpty(s[i])){
	    skip(s,i);
	    if(i>s.length())s[pos++]=0;
	    else s[pos++]=' ';
	}
	else {
	    s[pos++]=s[i++];
	}
    }
    reverse(s,0,pos-2);
    int st=0;
    for(int t=0;t<pos;t++){
	if(s[t]==' ' || s[t]=='\n' || s[t]=='\t'|| s[t]==0){
	    reverse(s,st,t-1);
	    st=t+1;
	}
    }
    s=s.substr(0,pos-1);
}
int main(){
    freopen("in.dat","r",stdin);
    string s="";
    string str;
    cin>>s;
    while(cin>>str)s+=" "+str;
    s="   "+s+"   ";
    cout<<s;
    cout<<"end"<<endl;
    reverseWords(s);
    cout<<s;
    cout<<"end"<<endl;
    return 0;
}
