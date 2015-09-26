#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
	if (NULL == head) return head;
	ListNode addition(-1);
	addition.next = head;
	ListNode *first = &addition;
	while(first->next) {
		if (first->next->val == val) {
			ListNode *tmp = first->next;
			first->next = tmp->next;
			cout<<tmp->val<<endl;
			free(tmp);
		}
		else first = first->next;
	}
	return addition.next;
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
	ListNode a(1), b(2), c(2), d(2), e(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	print_list(&a);
	ListNode * res = removeElements(&a, 2);
	getchar();
	print_list(res);
	return 0;
}
