#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x):val(x),next(NULL){}
};

void reorderList(ListNode *head){
    int n=0;
    ListNode *p=head;
    while(p){
	n++;
	p=p->next;
    }
    if(n<=2)return ;

    int step=(n-1)>>1;
    p=head;
    for(int i=0;i<step;i++)p=p->next;

    ListNode *tmp,*invertP;
    invertP=p->next;
    p->next=NULL;
    while(invertP){
	tmp=invertP;
	invertP=invertP->next;
	tmp->next=p->next;
	p->next=tmp;
    }

    ListNode *frontpartP,*backpartP;
    backpartP=p->next;
    p->next=NULL;
    frontpartP=head;
    while(frontpartP && backpartP){
	tmp=backpartP;
	backpartP=backpartP->next;
	tmp->next=frontpartP->next;
	frontpartP->next=tmp;
	frontpartP=frontpartP->next->next;
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
    int n;
    ListNode assistant(-1);
    ListNode *p=&assistant;
    while(cin>>n){
	p->next=new ListNode(n);
	p=p->next;
    }
    p->next=NULL;

    printList(assistant.next);
    reorderList(assistant.next);
    printList(assistant.next);
    return 0;
}
