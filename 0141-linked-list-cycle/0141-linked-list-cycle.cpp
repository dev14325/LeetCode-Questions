class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        while (head) {
            if (visited.find(head) != visited.end()) {
                return true; // If the current node is in the set, a cycle is detected
            }

            visited.insert(head);
            head = head->next;
        }

        return false; // No cycle found
    }
};
