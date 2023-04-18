/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*>> minHeap;
//         for (auto list : lists) {
//             if (list != nullptr) {
//                 minHeap.push(list);
//             }
//         }

//         // Create a result linked list.
//         ListNode* result = nullptr;
//         ListNode* prev = nullptr;

//         // While the min heap is not empty, do the following:
//         while (!minHeap.empty()) {
//             // Pop the root node of the min heap and store it in a variable.
//             ListNode* node = minHeap.top();
//             minHeap.pop();

//             // Append the popped node to the result linked list.
//             if (result == nullptr) {
//                 result = node;
//             } else {
//                 prev->next = node;
//             }
//             prev = node;

//             // Add the next element of the linked list that the popped node came from to the min heap.
//             if (node->next != nullptr) {
//                 minHeap.push(node->next);
//             }
//         }

//         // Return the result linked list.
//         return result;
        if (lists.empty()) {
            return nullptr;
        }
        int n = lists.size();
        if (n == 1) {
            return lists[0];
        }
        int mid = n / 2;
        vector<ListNode*> left(lists.begin(), lists.begin() + mid);
        vector<ListNode*> right(lists.begin() + mid, lists.end());
        ListNode* l1 = mergeKLists(left);
        ListNode* l2 = mergeKLists(right);
        return merge(l1, l2);
    }
};