#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int calculate(string s) {
    int pre_n = 0;
    int n = 0;
    int ret = 0;
    char opt = '#';

    int i = 0;
    int len = s.size();
    while(i <= len) {
        char c = s[i];
        if (i < len && isdigit(c)) n = n * 10 + c - '0';

        else if (i == len || !isspace(c)) {
            if ('+'==opt || '-'==opt || '#'==opt) {
                if ('-'==opt) n = -n;
                ret += pre_n;
                pre_n = n;
            }
            else if ('*' == opt) pre_n = pre_n * n;
            else if ('/' == opt) pre_n = pre_n / n;

            n = 0;
            opt = c;
        }
        i++;
    }
    ret += pre_n;
    return ret;
}

int main()
{
    string str;
    while(getline(cin, str)) {
        cout<<calculate(str)<<endl;
    }
    return 0;
}
