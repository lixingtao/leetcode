#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<int> preorderTraversal(TreeNode *root){
    vector<int >ret;
    if(!root)return ret;

    stack<TreeNode *> stk;
    stk.push(root);
    while(!stk.empty()){
	TreeNode *p=stk.top();
	stk.pop();
	ret.push_back(p->val);
	if(p->right)stk.push(p->right);
	if(p->left)stk.push(p->left);
    }
    return ret;
}

void printVector(vector<int> vet){
    for(int i=0;i<vet.size();i++){
	cout<<vet[i]<<'\t';
    }
    cout<<endl;
}

int main(){
    TreeNode a(1),b(2),c(3);
    a.left=&b;
    a.right=&c;
    printVector(preorderTraversal(&a));
    return 0;
}
