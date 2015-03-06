#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left,*next,*right;
    TreeLinkNode (int x):val(x),left(NULL),right(NULL),next(NULL){}
};

/*
void connect (TreeLinkNode *root){
    if(!root)return ;
    if(root->left){
	root->left->next=root->right;
	connect(root->left);
    }
    if(root->right){
	if(root->next)
	    root->right->next=root->next->left;
	connect(root->right);
    }
}

*/
/*
void connect(TreeLinkNode *root){
    if(!root)return ;
    TreeLinkNode *upperLevelFirst=root;
    while(upperLevelFirst){
	TreeLinkNode *cur=upperLevelFirst;
	while(cur){
	    TreeLinkNode *nt=NULL;
	    if(cur->next)nt=cur->next->left ? cur->next->left : cur->next->right;
	    if(cur->left)cur->left->next=cur->right ? cur->right : nt;
	    if(cur->right)cur->right->next=nt;
	    cur=cur->next;
	}
	upperLevelFirst=upperLevelFirst->left ? upperLevelFirst->left : upperLevelFirst->right;
    }
}
*/
void connect(TreeLinkNode *root){
    if(!root)return ;
    TreeLinkNode *upperLevelFirst=root;
    TreeLinkNode *pre,*cur;
    while(upperLevelFirst){
	cur=upperLevelFirst;
	pre=upperLevelFirst=NULL;
	while(cur){
	    if(cur->left){
		if(pre)pre=pre->next=cur->left;
		else upperLevelFirst=pre=cur->left;
	    }
	    if(cur->right){
		if(pre)pre=pre->next=cur->right;
		else upperLevelFirst=pre=cur->right;
	    }
	    cur=cur->next;
	}
    }
}

void printByNext(TreeLinkNode *root){
    if(!root)return;
    TreeLinkNode *p;
    for(p=root;p;p=p->next)cout<<p->val<<'\t';
    cout<<endl;
    printByNext(root->left);
}

int main(){
    freopen("in.dat","r",stdin);
    TreeLinkNode a(1),b(2),c(3),d(4),e(5),f(6),g(7);
    /*a.left=&b;
    a.right=&c;
    b.left=&d;
    b.right=&e;
    c.left=&f;
    c.right=&g;*/
    //printByNext(&a);
    a.left=&b;
    a.right=&c;
    b.left=&d;
    c.right=&e;
    connect(&a);
    printByNext(&a);
    return 0;
}
