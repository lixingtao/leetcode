#include <vector>
#include <cstring>
#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int maxn=1024*1024;

int Hash(string s){
    int ret=0;
    for(int i=0;i<s.length();i++){
	ret=ret<<2;
	switch(s[i]){
	    case 'A': ret+=0;break ;
	    case 'C': ret+=1;break ;
	    case 'G': ret+=2;break;
	    case 'T': ret+=3;break;
	    default :return -1;
	}
    }
    return ret;
}
#ifndef MAP
bool mmap[maxn];
bool vis[maxn];
#endif

vector<string> findRepeatedDnaSequences(string s){
    /*map<string,int>mmap;
    vector<string> vet;
    map<string,int>::iterator it;
    for(int i=0;i<=(int)s.length()-10;i++){
	string sub=s.substr(i,10);
	it=mmap.find(sub);
	if(it!=mmap.end()){
	    if(mmap[sub]==1){
		vet.push_back(sub);
		mmap[sub]==-1;
	    }
	}
	else mmap[sub]=1;
    }
    return vet;*/
    /*vector<string> vet;
    int len=s.length();
    vector<bool > vis(len,0);
    for(int i=0;i<len-10;i++)if(!vis[i]){
	string sub=s.substr(i,10);
	int pos=s.find(sub,i+1);
	if(pos!=string::npos){
	    vet.push_back(sub);
	    while(pos!=string::npos){
		vis[pos]=true;
		pos=s.find(sub,pos+1);
	    }
	}
    }
    return vet;*/
#ifdef MAP
    vector<string> vet;
    unordered_map<int,int> mmap;
    int len=s.length();
    for(int i=0;i<=len-10;i++){
	string sub=s.substr(i,10);
	int h=Hash(sub);
	if(mmap.find(h)==mmap.end())mmap[h]=1;
	else{
	    if(mmap[h]==1){
		mmap[h]=-1;
		vet.push_back(sub);
	    }
	}
    }
    return vet;
#endif
#ifndef MAP
    vector<string> vet;
    memset(mmap,false,sizeof(mmap));
    memset(vis,false,sizeof(vis));
    int len=s.length();
    for(int i=0;i<=len-10;i++){
	string sub=s.substr(i,10);
	int h=Hash(sub);
	if(!mmap[h])mmap[h]=true;
	else{
	    if(!vis[h]){
		vis[h]=true;
		vet.push_back(sub);
	    }
	}
    }
    return vet;
#endif
}

int main()
{
    freopen("in.dat","r",stdin);
    string s;
    cin>>s;
    vector<string> vet=findRepeatedDnaSequences(s);
    for(int i=0;i<vet.size();i++)cout<<vet[i]<<endl;
    return 0;
}
