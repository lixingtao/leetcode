#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    if (!root) return ret;

    queue<TreeNode *> que;
    que.push(root);

    while(!que.empty()) {
        int size = que.size();
        for (int i = 1; i <= size; i++) {
            TreeNode *p = que.front();
            que.pop();
            if (p->left) que.push(p->left);
            if (p->right) que.push(p->right);

            if (i == size) ret.push_back(p->val);
        }
    }

    return ret;
}

int main()
{
    return 0;
}
