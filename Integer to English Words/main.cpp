#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 11;

string  unit_vet[maxn * 2] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string  tens_vet[maxn] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

static string get_str(int n) {
    int a = n/100;
    string ret = "";
    if (a) ret += unit_vet[a] + " Hundred";
    int b = n % 100;
    if (b) {
        if (!ret.empty()) ret += " ";
        if (b >=20) {
            if (b%10) {
                ret += tens_vet[b/10] + " " + unit_vet[b%10];
            }
            else ret += tens_vet[b/10];
        }
        else {
            ret += unit_vet[b];
        }
    }
    if (ret.empty()) ret = "Zero";
    return ret;
}

string numberToWords(int num) {
    int u = num % 1000;
    int t = num / 1000 % 1000;
    int m = num / 1000000 % 1000;
    int b = num / 1000000000 % 1000; 
    string ret = "";
    if (b) ret += get_str(b) + " Billion";
    if (m) {
        if (!ret.empty()) ret += " ";
        ret += get_str(m) + " Million";
    }
    if (t) {
        if (!ret.empty()) ret += " ";
        ret += get_str(t) + " Thousand";
    }
    if (u) {
        if (!ret.empty()) ret += " ";
        ret += get_str(u);
    }
    
    if (ret.empty()) ret = "Zero";
    return ret;
}

int main()
{
    int n;
    while(cin>>n) {
        cout<<numberToWords(n)<<endl;
    }
    return 0;
}
