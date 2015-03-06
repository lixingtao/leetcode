#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x): val(x),next(NULL){}
};
ListNode * getIntersectionNode(ListNode *headA,ListNode *headB){
    if(!headA || !headB)return NULL;
    ListNode *pa,*pb;
    int lena,lenb;
    lena=lenb=0;
    for(pa=headA;pa;pa=pa->next)lena++;
    for(pb=headB;pb;pb=pb->next)lenb++;

    pa=headA;
    pb=headB;
    if(lena>lenb)
	for(int i=0;i<lena-lenb;i++)pa=pa->next;
    else if(lenb>lena)
	for(int i=0;i<lenb-lena;i++)pb=pb->next;

    while(pa && pb){
	if(pa==pb)return pa;
	pa=pa->next;
	pb=pb->next;
    }

    return NULL;
}
int main(){
    ListNode la1(1),la2(2);
    ListNode lb1(1);
    ListNode l3(3),l4(4);
    la1.next=&la2;
    la2.next=&l3;
    l3.next=&l4;
    lb1.next=&l3;
    cout<<getIntersectionNode(&la1,&lb1)->val<<endl;
    return 0;
}
