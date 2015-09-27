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

void deleteNode(ListNode* node) {
    if (!node || !(node->next)) return ;
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{
    return 0;
}
