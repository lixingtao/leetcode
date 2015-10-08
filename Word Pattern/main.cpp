#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

bool wordPattern(string pattern, string str) {
    map<char, string> c_to_str;
    map<string, char> str_to_c;

    vector<string> str_vet;
    string tmp = "";

    for (int i = 0; i < str.length(); i++) {
        if (' ' == str[i]) {
            str_vet.push_back(tmp);
            tmp = "";
        }
        else tmp += str[i];
    }
    if (!tmp.empty()) str_vet.push_back(tmp);


    if (pattern.length() != str_vet.size()) return false;

    for (int i = 0; i < pattern.length(); i++) {
        if (c_to_str.find(pattern[i]) == c_to_str.end() && str_to_c.find(str_vet[i]) == str_to_c.end()) 
            c_to_str[pattern[i]] = str_vet[i], str_to_c[str_vet[i]] = pattern[i];
        else {
            if (c_to_str.find(pattern[i]) == c_to_str.end() || str_to_c.find(str_vet[i]) == str_to_c.end() ||
                    (c_to_str[pattern[i]] != str_vet[i]))
                return false;
        }
    }
    return true;
}

int main()
{
    string pattern, str;
    pattern = "abba";
    str = "dog cat cat dog";
    cout<<wordPattern(pattern, str)<<endl;

    return 0;
}
