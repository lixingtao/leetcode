///桶排序，最大差值
///时间复杂度O(n)，空间复杂度O(n)
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int maximumGap(vector<int> &num) {
        int len=num.size();
        if(len<2)return 0;
        int bucketL[len+1];
        int bucketR[len+1];
        memset(bucketL,-1,sizeof(bucketL));
        memset(bucketR,-1,sizeof(bucketR));

        int ma=0;
        int mi=(1<<31)-1;
        for(int i=0;i<len;i++){
                if(ma<num[i])ma=num[i];
                if(mi>num[i])mi=num[i];
        }
        double  gap=double(ma-mi+1)/len;  ///计算gap时要加1是为了让最大的数字落在第len-1个桶中，而不是第len个桶中
        for(int i=0;i<len;i++){
                int bi=(int)((num[i]-mi)/gap);

                if(bucketL[bi]==-1)bucketL[bi]=num[i];
                else if(bucketL[bi]>num[i])bucketL[bi]=num[i];
                if(bucketR[bi]==-1)bucketR[bi]=num[i];
                else if(bucketR[bi]<num[i])bucketR[bi]=num[i];
        }

        int ans=0;
        int pre=-1;
        for(int i=0;i<len;i++){
                if(bucketL[i]!=-1){
                        if(pre!=-1) ans=max(bucketL[i]-pre,ans);
                        pre=bucketL[i];
                }
                if(bucketR[i]!=-1){
                        pre=bucketR[i];
                }
        }
        return ans;
}

int main()
{
        freopen("in.dat","r",stdin);
        vector<int > vet;
        int n;
        while(cin>>n)vet.push_back(n);
        cout<<maximumGap(vet)<<endl;
        return 0;
}
