#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef int64_t LL;

string itos(LL  n){
    string ret="";
    if(!n)return "0";
    while(n){
	ret=(char )(n%10+'0')+ret;
	n=n/10;
    }
    return ret;
}
string fractionToDecimal(int numberator,int denominator){
    if(numberator==0)return "0";
    vector<int> quo;
    vector<int> rem;
    string ret="";
    if((numberator ^ denominator)<0)ret="-";

    LL num,den;
    num=numberator;
    den=denominator;
    num=num<0?-num:num;
    den=den<0?-den:den;
    
    ret+=itos(num/den);	//整数部分

    num=num%den;
    if(num==0)return ret;

    int tag=0;
    int s=0;
    while(num && !tag){
	rem.push_back(num);
	num*=10;
	quo.push_back(num/den);
	num=num%den;
	for(int i=0;i<rem.size();i++)if(num==rem[i]){
	    tag=1;
	    s=i;
	    break;
	}
    }

    ret+='.';
    if(!tag)for(int i=0;i<quo.size();i++)ret+=(char)(quo[i]+'0');
    else{
	for(int i=0;i<quo.size();i++){
	    if(i==s)ret+='(';
	    ret+=(char)(quo[i]+'0');
	}
	ret+=')';
    }
    return ret;

}
int main(){
    int numberator,denominator;
    while(cin>>numberator>>denominator){
	cout<<fractionToDecimal(numberator,denominator)<<endl;
    }
    return 0;
}
