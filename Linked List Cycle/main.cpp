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

bool hasCycle(ListNode *head){
    if(!head)return false;

    ListNode *fast=head;
    ListNode *slow=head;

    while(fast->next && (fast=fast->next->next)){
	slow=slow->next;
	if(fast==slow)return true;
    }
    return false;
}

int main(){
    ListNode la(1),lb(2),lc(3),ld(4);
    la.next=&lb;
    lb.next=&lc;
    lc.next=&ld;
    //ld.next=&lb;
    if(hasCycle(&la))cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
