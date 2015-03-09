#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &numbers,int target){
	vector<int> ret(2);
	int len=numbers.size();
	if(len<=1)return ret;
	vector<int >buf(numbers);
	sort(buf.begin(),buf.end());

	if(target<buf[0]*2 || target>buf[len-1]*2)return ret;

	int s=0;
	int t=len-1;
	int n1,n2;
	while(s<=t){
		int n=buf[t]+buf[s];
		if(n==target){
			n1=buf[s];
			n2=buf[t];
			break;
		}
		else if(n>target)t--;
		else s++;
	}

	for(int i=0;i<len;i++){
		if(numbers[i]==n1 || numbers[i]==n2){
			ret[0]=i+1;
			if(numbers[i]==n2)n2=n1;
			for(i++;i<len;i++)if(numbers[i]==n2){
				ret[1]=i+1;
				break;
			}
			break;
		}
	}

	return ret;
}

int main()
{
	freopen("in.dat","r",stdin);
	vector<int> vet;
	int target,n;
	cin>>target;
	while(cin>>n)vet.push_back(n);
	vector<int> ret=twoSum(vet,target);
	cout<<ret[0]<<","<<ret[1]<<endl;
	return 0;
}
