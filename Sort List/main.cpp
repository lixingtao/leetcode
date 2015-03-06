#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


ListNode *sortCore(ListNode *head){
    if(!head)return NULL;
    if(head->next==NULL)return head;

    int len=0;///将head分成尽量等长的两部分
    ListNode *p=head;
    while(p){
	len++;
	p=p->next;
    }
    int mid=(len-1)>>1;
    p=head;
    for(int i=0;i<mid;i++)p=p->next;
    ListNode *pb=p->next;
    ListNode *pa=head;
    p->next=NULL;

    ///分治，计算部分
    pa=sortCore(pa);
    pb=sortCore(pb);

    ///合并
    ListNode ret(-1);///添加一个结点，便于操作
    ret.next=NULL;
    p=&ret;
    while(pa && pb){
	if(pa->val < pb->val){
	    p->next=pa;
	    pa=pa->next;
	    p=p->next;
	}
	else {
	    p->next=pb;
	    pb=pb->next;
	    p=p->next;
	}
    }

    if(pa)p->next=pa;
    if(pb)p->next=pb;
    return ret.next;
}

ListNode *sortList(ListNode *head){
    return sortCore(head);
}

/*
void qsort(ListNode *first,ListNode *end,int len){
    if(len<=1)return ;
    int t=(len-1)>>1;

    ListNode *p=first;
    for(int i=0;i<t;i++)
	p=p->next;

    swap(first->val,p->val);

    ListNode *split=first;
    for(p=first->next;p;p=p->next){
	if(first->val > p->val) {
	    split=split->next;
	    swap(split->val,p->val);
	}
	if(p==end)break;
    }
    swap(first->val,split->val);

    if(split==first)
	qsort(split->next,end,len-1);
    else {
	int cnt=1;
	for(p=first;p->next!=split;p=p->next)cnt++;
	qsort(first,p,cnt);
	if(split!=end)qsort(split->next,end,len-cnt-1);
    }
}
ListNode *sortList(ListNode *head){
    if(!head)return NULL;

    ListNode *p=head;
    int cnt=1;
    for(;p->next;p=p->next)cnt++;

    qsort(head,p,cnt);
    return head;
}
*/
void printList(ListNode *p){
    while(p){
	cout<<p->val<<endl;
	p=p->next;
    }
}

int main(){
    freopen("in.dat","r",stdin);
    ListNode *list=new ListNode (-1);
    ListNode *p=list;
    int n;
    while(cin>>n){
	p->next=new ListNode(n);
	p=p->next;
    }
    p->next=NULL;
    p=sortList(list->next);
    printList(p);
    return 0;
}
