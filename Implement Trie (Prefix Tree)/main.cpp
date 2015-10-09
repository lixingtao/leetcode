#include <map>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            next[i] = 0;
        }
        count = 0;
    }
public:
    TrieNode *next[26];
    int count;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(p->next[index] == NULL) 
                p->next[index] = new TrieNode();

            p = p->next[index];
            if (i == word.length() -1) p->count++;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * p = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (p->next[index] == NULL) return false;

            p = p->next[index];

            if (i == word.length() - 1 && p->count) return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i  = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';

            if (p->next[index] == NULL) return false;

            p = p->next[index];
        }

        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
    Trie trie;
    trie.insert("somestring");
    cout<<trie.search("somestring")<<endl;
    cout<<trie.search("key")<<endl;
    trie.insert("key");
    cout<<trie.search("key")<<endl;
    cout<<trie.search("somestring")<<endl;
    cout<<trie.search("some")<<endl;
    cout<<trie.startsWith("some")<<endl;
    return 0;
}
