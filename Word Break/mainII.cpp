#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

void df(vector<vector<int> >&pre,string s,int end,vector<string> &ans,vector<int> &mem){
    mem.push_back(end);
    if(end==-1){
	string add=s.substr(mem[mem.size()-1]+1,mem[mem.size()-2]-mem[mem.size()-1]);
	for(int i=mem.size()-2;i>=1;i--){ 
	    add+=" "+s.substr(mem[i]+1,mem[i-1]-mem[i]);
	}
	ans.push_back(add);
	mem.pop_back();
	return ;
    }

    for(int i=0;i<pre[end].size();i++)
	df(pre,s,pre[end][i],ans,mem);

    mem.pop_back();
}

vector<string> wordBreak(string s,unordered_set<string> &dict){
    vector<string> ans;
    if(s.length()==0 || dict.size()==0)return ans;
    vector<vector<int> > pre(s.length());
    for(int i=0;i<s.length();i++){
	for(int j=0;j<=i;j++)if(dict.find(s.substr(j,i-j+1))!=dict.end() && (j==0 || pre[j-1].size()))
	    pre[i].push_back(j-1);
    }
    vector<int> mem;
    df(pre,s,s.length()-1,ans,mem);
    return ans;
}
int main(){
    freopen("in.dat","r",stdin);
    string s;
    unordered_set<string> dict;
    cin>>s;
    string tmp;
    while(cin>>tmp)dict.insert(tmp);
    vector<string> ans;
    ans=wordBreak(s,dict);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
    cout<<endl;
    return 0;
}
