#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode *removeNthFromEnd(ListNode *head,int n){
	int len=0;
	ListNode *p;
	for(p=head;p;p=p->next)len++;
	int pos=len-n+1;
	
	ListNode addition(-1);
	addition.next=head;
	p=&addition;
	
	for(int i=0;i<pos-1;i++)p=p->next;
	ListNode *buf=p->next;
	p->next=buf->next;	
	delete buf;

	return addition.next;
}

void printList(ListNode *p){
	while(p){
		cout<<p->val<<'\t';
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	freopen("in.dat","r",stdin);
	ListNode addition(-1);
	ListNode *p=&addition;
	int n;
	while(cin>>n){
		p->next=new ListNode(n);
		p=p->next;
	}
	printList(addition.next);
	cin>>n;
	p=removeNthFromEnd(addition.next,2);
	printList(p);
	return 0;
}
