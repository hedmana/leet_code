#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = head, *second = head;

        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        if (!first) {
            return head->next;
        }

        while (first->next) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        return head;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *result = solution.removeNthFromEnd(head, 2);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}