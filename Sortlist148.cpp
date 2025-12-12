#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // split list into two halves
        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr; // break

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        return doMerge(leftSorted, rightSorted);
    }

private:
    // Merge two sorted lists and return head of merged list
    ListNode* doMerge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        // attach remaining nodes
        if (left != nullptr) tail->next = left;
        else tail->next = right;

        return dummy.next;
    }

    // Return middle node (end of left half).
    // For list length 2k or 2k+1, this returns the node at index k-1 (0-based),
    // so splitting at mid->next divides the list reasonably evenly.
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ListNode* node = new ListNode(x);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    Solution sol;
    ListNode* sorted = sol.sortList(head);

    // print sorted list values space-separated
    bool first = true;
    for (ListNode* cur = sorted; cur != nullptr; cur = cur->next) {
        if (!first) cout << " ";
        cout << cur->val;
        first = false;
    }
    cout << "\n";

    // (Optional) cleanup allocated nodes to avoid leaks
    while (sorted) {
        ListNode* tmp = sorted->next;
        delete sorted;
        sorted = tmp;
    }

    return 0;
}
