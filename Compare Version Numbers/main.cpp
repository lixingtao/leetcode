///版本号，字符串处理
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int getNum(string str,int &index){
        int ret=0;
        if(index<str.length() && (str[index]>'9' || str[index]<'0'))index++;         ///去掉前面的非数字字符，本题中就是 '.'
        for(;index<str.length() && str[index]<='9' && str[index]>='0';index++)ret=ret*10+str[index]-'0';

        return ret;
}

int compareVersion(string version1, string version2) {
        int index1,index2;
        index1=index2=0;
        while(index1<version1.length() &&index2<version2.length()){
                int v1=getNum(version1,index1);
                int v2=getNum(version2,index2);
                if(v1>v2)return 1;
                if(v1<v2)return -1;
        }

        while(index1<version1.length()){
                int v1=getNum(version1,index1);
                if(v1>0)return 1;               ///后面的数字是0的话，还是相等
        }
        while(index2<version2.length()){
                int v2=getNum(version2,index2);
                if(v2>0)return -1;
        }
        return 0;
}

int main()
{
        string s1,s2;
        while(cin>>s1>>s2){
                cout<<compareVersion(s1,s2)<<endl;
        }
        return 0;
}
