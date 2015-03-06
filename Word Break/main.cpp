#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

bool wordBreak(string s,unordered_set <string> &dict){
    bool d[s.length()+1];
    memset(d,false,s.length()+1);
    d[0]=true;
    for(int i=0;i<s.length();i++){
	for(int j=i;j>=0;j--)if(dict.find(s.substr(j,i-j+1))!=dict.end() && d[j]){
	    d[i+1]=true;
	    break;
	}
    }
    return d[s.length()];
}
int main(){
    freopen("in.dat","r",stdin);
    unordered_set<string> dict;
    string s,tmp;
    cin>>s;
    while(cin>>tmp)dict.insert(tmp);
    if(wordBreak(s,dict))cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
