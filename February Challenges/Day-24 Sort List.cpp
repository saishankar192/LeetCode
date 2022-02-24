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
    ListNode* MergeLists(ListNode* a, ListNode* b){
    }
    
    ListNode* MergeSort(ListNode* head, int cnt){
        if(head->next == NULL)
            return head;
        
        int mid = cnt/2;
        int t = mid;
        ListNode* temp = head
        while(--t){
            temp = temp->next;
        }
        ListNode* next = temp->next;
        temp->next = NULL;
        
        head = MergeSort(head, mid);
        next = MergeSort(next, cnt-mid);
        
        return MergeLists(head, next);
    }
   
    ListNode* sortList(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        
        while(temp){
            cnt++;
            temp = temp->next
        }
        
        if(head)
            head = MergeSort(head, cnt);
        return head;
    }
};