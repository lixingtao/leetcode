#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 1000;

int add(unsigned int& ret, char c, int tag) {
    c -= '0';
    unsigned int mod = 1 << 31;
    if (tag == 1) mod--;
    if (ret > mod/10 || ret*10 > mod - c) {
        ret = mod;
        return ret;
    }
    ret = ret * 10 + c;
    return 0;
}

int myAtoi(string str) {
    int len = str.size();
    unsigned int ret = 0;
    int tag = 1;
    int p = 0;

    while(isspace(str[p]))p++;

    if ('-' == str[p]) tag = -1, p++;
    else if ('+' == str[p]) p++;

    for (; p < len; p++) {
        char c = str[p];
        if (!isdigit(c)) {
            return ret * tag;
        }
        if (add(ret, c, tag)) return ret;
    }
    return ret * tag;
}

int main()
{
    string str;
    while(cin>>str) {
        cout<<myAtoi(str)<<endl;
    }
    return 0;
}
