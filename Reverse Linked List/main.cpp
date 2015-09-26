#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseList(ListNode* head) {
    if (!head)return head;

    ListNode *addition = new ListNode(-1);
    addition->next = NULL;
    ListNode *p = head;

    while(p) {
        ListNode *tmp = p;
        p = p->next;
        tmp->next = addition->next;
        addition->next = tmp;
    }
    return addition->next;
}

void print_list(ListNode *head) {
    while(head) {
        printf("%d\t", head->val);
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    ListNode a(1), b(2), c(3);
    a.next = &b;
    b.next = &c;
    print_list(&a);
    print_list(reverseList(&a));
    return 0;
}
