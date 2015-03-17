#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode (int x): val(x),next(NULL){}
};

ListNode *mergeTwoLists(ListNode *l1,ListNode *l2){
	ListNode addition(-1);
	ListNode *pa=l1;
	ListNode *pb=l2;
	ListNode *p=&addition;
	ListNode *tmp;

	while(pa && pb){
		if(pa->val<pb->val){
			p->next=pa;
			p=p->next;
			pa=pa->next;
		}else {
			p->next=pb;
			p=p->next;
			pb=pb->next;
		}
	}

	if(pa)p->next=pa;
	if(pb)p->next=pb;

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
	int m,n;
	cin>>m>>n;
	ListNode addition(-1);
	ListNode *p=&addition;
	ListNode *pa,*pb;

	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		p->next=new ListNode(t);
		p=p->next;
	}
	pa=addition.next;

	p=&addition;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		p->next=new ListNode(t);
		p=p->next;
	}
	pb=addition.next;

	printList(pa);
	printList(pb);
	printList(mergeTwoLists(pa,pb));
	return 0;
}
