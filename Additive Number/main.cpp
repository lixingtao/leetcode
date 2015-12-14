#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

bool judge(string a, string b, string sum) {
    //cout<<a<<", "<<b<<", "<<sum<<endl;
    int lena = a.length();
    int lenb = b.length();
    int lens = sum.length();
    
    if (lens < lena || lens < lenb) return 0;
    int c = 0;
    while(lena > 0 && lenb > 0) {
        int tmp = a[lena-1] + b[lenb-1] - '0' - '0' + c;
        c = tmp / 10;
        tmp = tmp % 10;
        if (sum[lens-1] != tmp+'0') return 0;
        lena--;
        lenb--;
        lens--;
    }

    while(lena > 0) {
        int tmp = a[lena-1] + c -'0';
        c = tmp / 10;
        tmp = tmp % 10;
        if (sum[lens-1] != tmp+'0') return 0;
        lena--;
        lens--;
    }

    while(lenb > 0) {
        int tmp = b[lenb-1] + c - '0';
        c = tmp /10;
        tmp = tmp %10;
        if (sum[lens-1] != tmp+'0') return 0;
        lenb--;
        lens--;
    }

    if ((c==0 && lens==0) || (lens==1 && sum[0]==c+'0'))
        return 1;

    return 0;
}

bool df(string a, string b, string num) {
    int lena = a.length();
    int lenb = b.length();
    int lenn = num.length();
    int len = max(lena, lenb);
    if (!lenn) return 1;
    if (len > lenn) return 0;
    if ((a[0] == '0' && lena>1) || (b[0] == '0' && lenb>1) || (num[0] == '0' && lenn>1)) return 0;

    bool ret = judge(a, b, num.substr(0, len));
    //cout<<a<<", "<<b<<", "<<num.substr(0, len)<<", ret:"<<ret<<endl;
    if (ret) {
        if (df(b, num.substr(0, len), num.substr(len)))
            return 1;
    }

    if (len+1 > lenn) return 0;

    ret = judge(a, b, num.substr(0, len+1));
    //cout<<a<<", "<<b<<", "<<num.substr(0, len+1)<<", ret:"<<ret<<endl;
    if (ret) {
        if (df(b, num.substr(0, len+1), num.substr(len+1)))
            return 1;
    }

    return 0;
}

bool isAdditiveNumber(string num) {
    int len = num.length();
    for (int i = 0; i < len-2; i++) {
        for (int j = i+1; j < len-1; j++) {
            if (df(num.substr(0, i+1), num.substr(i+1, j-i), num.substr(j+1)))
                return 1;
        }
    }

    return 0;
}

int main()
{
    string s;
    while(cin>>s) {
        cout<<s<<" is "<<isAdditiveNumber(s)<<endl;
    }
    return 0;
}

