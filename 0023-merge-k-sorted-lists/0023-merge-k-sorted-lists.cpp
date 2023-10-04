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
     ListNode* solve( ListNode* a, ListNode* b){
    if(a->next==NULL){
        a->next=b;
        return a;
    }
    // cout<<"here";
     ListNode* curr1=a;
     ListNode* next1=curr1->next;
     ListNode* curr2=b;
     ListNode* next2;
    while(next1!=NULL&&curr2!=NULL){
        if(curr1->val<=curr2->val&&curr2->val<next1->val){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            
            curr1=curr2;
            curr2=next2;
            
        }
        else {
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return a;
            }
        }
    }
    return a;
}

 ListNode* SortedMerge( ListNode* a,  ListNode* b)
{
    if(a==NULL)
        return b;
        
        if(b==NULL)
        return a;
        
        if(a->val<=b->val){
            return solve(a,b);
        }
        else{
            return solve(b,a);
        }
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        //merge list0 and list1
        ListNode* a=SortedMerge(lists[0],lists[1]);

        int n=lists.size();
        for(int i=2;i<n;i++){
            //merge remaining lists in merged list
            ListNode* b=SortedMerge(a,lists[i]);
            a=b;
        }
        return a;
    }
};