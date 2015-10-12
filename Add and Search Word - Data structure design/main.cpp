#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Trie {
    int count;
    Trie * next[26];
    Trie() {
        count = 0;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

class WordDictionary {
    Trie *root;
public:

    WordDictionary() {
        root = new Trie();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.length();
        if (!len) return ;

        Trie *p = root;
        for (int i = 0; i < len; i++) {
            int t = word[i] - 'a';
            if (!(p->next[t])) p->next[t] = new Trie();
            p = p->next[t];
        }
        p->count++;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int len = word.length();
        if (!len) return false;

        return searchCore(word, 0, len, root);
    }

    bool searchCore(string word, int cur, int len, Trie *rt) {
        if (!rt) return false;

        if (cur == len) {
            return !!(rt->count);
        }

        if (word[cur] == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchCore(word, cur+1, len, rt->next[i])) return true;
            }
            return false;
        }
        else {
            int t = word[cur] - 'a';
            return searchCore(word, cur+1, len, rt->next[t]);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("word");
    cout<<wordDictionary.search("w.od");
    cout<<endl;
    return 0;
}
