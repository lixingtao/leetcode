#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

bool strEnd(char c){
	if(c=='\n' || c=='\t' || c==EOF)return true;
	return false;
}

void decompose(char *s,int *a,int &n){
	n=0;
	int t=0;
	int i=0;
	for(;s[i]==' ';i++);
	while( !strEnd(s[i]) ){
		if(s[i]>='0' && s[i]<='9')t=t*10+s[i]-'0',i++;
		else{
			 n++,t=0;
			 while((s[i]<'0' || s[i]>'9') && strEnd(s[i])==false)i++;
		}
		a[n]=t;
	}
	n++;
}

void print(int *a,int n){
	for(int i=0;i<n;i++)cout<<a[i]<<'\t';
	cout<<endl;
}

void printList(ListNode *p){
	while(p){
		cout<<p->val<<'\t';
		p=p->next;
	}
	cout<<endl;
}

ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
	ListNode *ld=new ListNode(-1);
	ListNode *pd=ld;

	int rem=0;
	while(l1 && l2){
		int n=l1->val + l2->val + rem;
		pd->next=new ListNode (n%10);
		pd=pd->next;
		rem=n/10;

		l1=l1->next;
		l2=l2->next;
	}

	while(l1){
		int n=l1->val + rem;
		pd->next=new ListNode(n%10);
		pd=pd->next;
		rem=n/10;

		l1=l1->next;
	}
	while(l2){
		int n=l2->val + rem;
		pd->next=new ListNode (n%10);
		pd=pd->next;
		rem=n/10;

		l2=l2->next;
	}
	while(rem){
		pd->next=new ListNode(rem%10);
		pd=pd->next;
		rem=rem/10;
	}

	return ld->next;
}

int main()
{
	freopen("in.dat","r",stdin);
	char buf[2001];
	int a[2001];
	int lena,lenb;
	ListNode *la=new ListNode (-1);
	ListNode *lb=new ListNode (-1);
	ListNode *pa=la;
	ListNode *pb=lb;

	fgets(buf,sizeof(buf),stdin);
	decompose(buf,a,lena);
	print(a,lena);
	for(int i=0;i<lena;i++){
		pa->next=new ListNode(a[i]);
		pa=pa->next;
	}
	printList(la->next);

	fgets(buf,sizeof(buf),stdin);
	decompose(buf,a,lenb);
	print(a,lenb);
	for(int i=0;i<lenb;i++){
		pb->next=new ListNode(a[i]);
		pb=pb->next;
	}
	printList(lb->next);

	printList(addTwoNumbers(la->next,lb->next));
	return 0;
}
