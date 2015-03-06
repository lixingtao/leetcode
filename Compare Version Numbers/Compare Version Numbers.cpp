#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int getNum(string str,int &index){
    int ret=0;
    while(index<str.length() && str[index]!='.'){
	ret=ret*10+(str[index]-'0');
	index++;
    }
    index++;
    return ret;
}

int compareVersion(string version1,string version2){
    int index1;
    int index2;
    index1=index2=0;
    while(index1<version1.length() || index2<version2.length()){
	int n1=getNum(version1,index1);
	int n2=getNum(version2,index2);
	if(n1>n2)return 1;
	else if(n1<n2)return -1;
    }
    return 0;
}
int main(){
    freopen("in.dat","r",stdin);
    string  n1,n2;
    while(cin>>n1>>n2)cout<<compareVersion(n1,n2)<<endl;
    return 0;
}
