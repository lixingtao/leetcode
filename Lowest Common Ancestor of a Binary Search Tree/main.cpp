#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //TreeNode *tp = p;
    //TreeNode *tq = q;
    if (p->val > q->val) swap(p, q);
    //cout<<p->val<<"\t"<<q->val<<endl;
    TreeNode *cur = root;
    while(cur) {
        if (p->val <= cur->val && q->val >= cur->val) return cur;
        else {
            if (cur->val > q->val) cur = cur->left;
            else cur = cur->right;
        }
    }
    return NULL;
}

int main()
{
    TreeNode a(2), b(1);
    a.left = &b;
    cout<<lowestCommonAncestor(&a, &a, &b)->val<<endl;
    return 0;
}
