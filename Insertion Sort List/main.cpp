#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x): val(x),next(NULL){}
};

ListNode *insertionSortList(ListNode *head){
    if(!head)return NULL;
    ListNode assistant(-1);
    assistant.next=head;
    ListNode *p=head->next;
    head->next=NULL;

    while(p){
	ListNode *insertionBehind=&assistant;
	while(insertionBehind->next && insertionBehind->next->val < p->val)
	    insertionBehind=insertionBehind->next;
	ListNode *tmp=p;
	p=p->next;
	tmp->next=insertionBehind->next;
	insertionBehind->next=tmp;
    }

    return assistant.next;
}

void printList(ListNode *p){
    while(p){
	cout<<p->val<<'\t';
	p=p->next;
    }
    cout<<endl;
}

int main(){
    freopen("in.dat","r",stdin);
    ListNode assistant(-1);
    ListNode *p=&assistant;
    int n;
    while(cin>>n){
	p->next=new ListNode(n);
	p=p->next;
    }
    p->next=NULL;
    printList(assistant.next);
    printList(insertionSortList(assistant.next));
    return 0;
}
