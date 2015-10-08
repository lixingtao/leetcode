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


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || root == p || root == q) return root;

	TreeNode *p_left = lowestCommonAncestor(root->left, p, q);
	TreeNode *p_right = lowestCommonAncestor(root->right, p, q);

	if (!p_left) return p_right;
	if (!p_right) return p_left;

	return root;
}

int main()
{
	TreeNode a(1), b(2), c(3);
	a.left = &b;
	a.right = &c;
	cout<<lowestCommonAncestor(&a, &b, &c)->val<<endl;
    return 0;
}
