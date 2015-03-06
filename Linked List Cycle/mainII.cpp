#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

/*
bool hasCycle(ListNode *head){
    if(!head || head->next==NULL)return false;

    ListNode *step=head;
    ListNode *doubleStep=head->next;
    while(step && doubleStep){
	if(step==doubleStep)return true;

	step=step->next;
	if(doubleStep->next)doubleStep=doubleStep->next->next;
	else return false;
    }
    return false;
}
*/

ListNode *  hasCycle(ListNode *head){
    if(!head)return NULL;

    ListNode *fast=head;
    ListNode *slow=head;

    while(fast->next && (fast=fast->next->next)){
	slow=slow->next;
	if(fast==slow)return fast;
    }
    return NULL;
}

ListNode *detectCycle(ListNode *head){
    ListNode *insideCycle=hasCycle(head);
    if(!insideCycle)return NULL;

    int cyclelen=1;
    ListNode *p=insideCycle->next;
    while(p!=insideCycle){
	p=p->next;
	cyclelen++;
    }

    ListNode *findp=head;
    p=head;
    for(int i=0;i<cyclelen;i++)p=p->next;
    while(1){
	if(findp==p)return p;
	findp=findp->next;
	p=p->next;
    }
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
    ListNode la(-1);
    ListNode *p=&la;
    vector<ListNode *>vet;
    int n;
    int in;
    cin>>in;
    while(cin>>n){
	p->next=new ListNode(n);
	vet.push_back(p->next);
	p=p->next;
    }
    p->next=vet[in];
    ListNode *entry=detectCycle(la.next);
    if(!entry)cout<<"no cycle"<<endl;
    else cout<<entry->val<<endl;
    return 0;
}
