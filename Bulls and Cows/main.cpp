#include <map>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

string getHint(string secret, string guess) {
    int lena = secret.size();
    int lenb = guess.size();
    int len = min(lena, lenb);
    int mp[128];
    int mpb[128];
    memset(mp, 0, sizeof(mp));
    memset(mpb, 0, sizeof(mpb));
    int cnta = 0;
    int cntb = 0;

    for (int i = 0; i < len; i++) {
        if (secret[i] == guess[i]) cnta ++;
        else {
            mp[secret[i]]++;
            mpb[guess[i]]++;
        }
    }

    for (int i = 0; i < 128; i++) {
        cntb += min(mp[i], mpb[i]);
    }

    char s[100];
    sprintf(s, "%dA%dB", cnta, cntb);
    return s;
}

int main()
{
    string secret = "1122";
    string guess = "2211";
    cout<<getHint(secret, guess)<<endl;
    return 0;
}
