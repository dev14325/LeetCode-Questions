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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
       
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }

        sort(v.begin(),v.end());
        ListNode dummy(0);
        ListNode* curr = &dummy;

        for(int x : v ){
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy.next;
        
    }
};