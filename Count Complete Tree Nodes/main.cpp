#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int find_pos(TreeNode *root, int l, int h) {
    if (l == h) return 1;
    if (!root->left) return 0;
    if (!root->right) return 1;

    TreeNode *p = root->right;
    int tmp = l + 1;
    while(p->left) p=p->left, tmp++;

    /*cout<<root->val<<endl;
    cout<<"tmp: "<<tmp<<endl;
    cout<<"h: "<<h<<endl;*/
    //cout<<(1<<(h-l-1))<<endl;

    if (tmp == h) return (1<<(h-l-1)) + find_pos(root->right, l+1, h);
    else return find_pos(root->left, l+1, h);
}

int countNodes(TreeNode* root) {
    if (!root) return 0;

    int h = 0;
    TreeNode *p = root;
    while(p->left) p=p->left, h++;

    return (1<<h) - 1 + find_pos(root, 0, h);
}


int main()
{
    TreeNode a(1), b(2), c(3), d(4), e(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    cout<<countNodes(&a)<<endl;
    return 0;
}
