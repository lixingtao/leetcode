#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode * rever_list(ListNode * head) {
    ListNode addition(-1);
    addition.next = NULL;
    while(head) {
        ListNode * tmp  = head;
        head = head->next;
        tmp->next = addition.next;
        addition.next = tmp;
    }
    return addition.next;
}

bool isPalindrome(ListNode* head) {
    int len = 0;
    ListNode *p = head;
    while(p) {
        len++;
        p = p->next;
    }

    if (len <= 1)return true;

    ListNode *front = head;
    ListNode *behind =  head;
    for (int i = 0; i < (1+len)/2; i++) {
        behind = behind->next;
    }

    behind = rever_list(behind);
    ListNode * rem = behind;

    bool ret = 1;
    for (int i = 0; i < len/2; i++) {
        if (front->val != behind->val) {
            ret = 0;
            break;
        }
        front = front->next;
        behind = behind->next;
    }

    rever_list(rem);
    return ret;
}

void print_list(ListNode *head) {
    while(head) {
        cout<<head->val<<"\t";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    ListNode a(1), b(2), c(3), d(2), e(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    //print_list(&a);
    cout<<isPalindrome(&a)<<endl;
    return 0;
}
