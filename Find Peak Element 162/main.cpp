///---
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
int findPeakElement(const vector<int> &num) {
        int index;
        if(num.size()<=1)return 0;
        if(num[0]>num[1])return 0;
        if(num[num.size()-1]>num[num.size()-2])return num.size()-1;
        for(int i=1;i<num.size()-1;i++){
                if(num[i]>num[i-1] && num[i]>num[i+1])
                        return i;
        }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
