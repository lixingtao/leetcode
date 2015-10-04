#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

map<TreeNode *, TreeNode *> pre;


TreeNode * bfs(TreeNode *root) {
    if (!root) return NULL;

    TreeNode *pleft = bfs(root->left);
    TreeNode *pright = bfs(root->right);
    if (pleft) pre[pleft] = root;
    if (pright) pre[pright] = root;

    return root;
}

TreeNode *find_common(TreeNode *p1, TreeNode * p2) {
    int len1 = 0, len2 = 0;
    TreeNode *tmp1 = p1, *tmp2 = p2;
    while(tmp1) {
        len1++; 
        tmp1 = pre[tmp1];
    }
    while(tmp2) {
        len2++;
        tmp2 = pre[tmp2];
    }

    if (!len1 || !len2) return NULL;

    tmp1 = p1;
    tmp2 = p2;

    int dlen = len1 - len2;

    while(dlen > 0) tmp1 = pre[tmp1], dlen--;
    while(dlen < 0) tmp2 = pre[tmp2], dlen++;

    while(tmp1 && tmp2) {
        if (tmp1 == tmp2) return tmp1;
        tmp1 = pre[tmp1];
        tmp2 = pre[tmp2];
    }

    return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    pre.clear();
    pre[root] = NULL;

    bfs(root);
    return find_common(p, q);
}

int main()
{
    return 0;
}
