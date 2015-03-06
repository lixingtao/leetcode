#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int numDistinct(string S,string T){
    if(S.length()<T.length())return 0;
    int d[T.length()];
    memset(d,0,sizeof(d));

    if(T[0]==S[0])d[0]=1;
    for(int i=1;i<S.length();i++){
	for(int j=T.length()-1;j>=1;j--)
	    if(T[j]==S[i])d[j]+=d[j-1];
	if(T[0]==S[i])d[0]++;
    }
    return d[T.length()-1];
}

int main(){
    freopen("in.dat","r",stdin);
    string S,T;
    while(cin>>S>>T)
	cout<<numDistinct(S,T)<<endl;
    return 0;
}
