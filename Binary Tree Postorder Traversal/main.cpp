#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

/*
vector<int> postorderTraversal(TreeNode *root){
    vector<int> ret;
    if(!root)return ret;
    
    stack<TreeNode *> stk;
    stk.push(root);
    while(!stk.empty()){
	TreeNode *p=stk.top();
	stk.pop();
	ret.insert(ret.begin(),p->val);
	if(p->left)stk.push(p->left);
	if(p->right)stk.push(p->right);
    }
    return ret;
}
*/

vector<int> postorderTraversal(TreeNode *root){
    vector<int> ret;
    if(!root)return ret;

    stack<TreeNode *>stk;
    stk.push(root);
    while(!stk.empty()){
	TreeNode *p=stk.top();
	stk.pop();
	ret.push_back(p->val);
	if(p->left)stk.push(p->left);
	if(p->right)stk.push(p->right);
    }
    for(int i=0;i<ret.size()/2;i++){
	int tmp=ret[i];
	ret[i]=ret[ret.size()-1-i];
	ret[ret.size()-1-i]=tmp;
    }
    return ret;
}

void printVector(vector<int> vet){
    for(int i=0;i<vet.size();i++)
	cout<<vet[i]<<'\t';
    cout<<endl;
}

int main(){
    freopen("in.dat","r",stdin);
    TreeNode a(3),b(1),c(2);
    a.right=&c;
    a.left=&b;
    printVector(postorderTraversal(&a));
    return 0;
}
