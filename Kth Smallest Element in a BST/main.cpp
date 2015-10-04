#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*map<TreeNode * , int> cnt_map;

int bfs(TreeNode *root) {
	if (!root) return 0;

	int left = bfs(root->left);
	int right = bfs(root->right);

	return cnt_map[root] = left + right + 1;
}

TreeNode * find_kth(TreeNode * root, int k) {
	if (!root) return NULL;

	int cnt_left = cnt_map[root->left];
	int cnt_right = cnt_map[root->right];

	if (cnt_left + 1 == k) return root;
	if (cnt_left >= k) return find_kth(root->left, k);
	else return find_kth(root->right, k-cnt_left-1);
}

int kthSmallest(TreeNode* root, int k) {
	cnt_map.clear();
	cnt_map[NULL] = 0;
	bfs(root);

	return find_kth(root, k)->val;
}*/

int kthSmallest(TreeNode* root, int k) {
	int cnt = 0;
	stack<TreeNode *> st;

	TreeNode * cur = root;
	while(cur || !st.empty()) {
		if (!cur) {
			cur = st.top();
			st.pop();
			cnt++;
			if (cnt == k) return cur->val;
			cur = cur->right;
		}
		else {
			st.push(cur);
			cur = cur->left;
		}
	}
}

int main() 
{
	TreeNode a(2), b(1), c(3);
	a.left = &b;
	a.right = &c;
	cout<<kthSmallest(&a, 3)<<endl;
	return 0;
}
