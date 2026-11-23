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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++n;
        }

        k %= n;
        if (k == 0) return head;

        // Form a circular list
        tail->next = head;

        // Move (n - k) steps to find the new tail
        int stepsToNewTail = n - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};

int main() {
    ListNode* head = new ListNode(0, new ListNode(1, new ListNode(2)));
    Solution sol;
    ListNode* res = sol.rotateRight(head, 4);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\n";
    return 0;
}