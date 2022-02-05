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
   ListNode* MergeLists(ListNode* a, ListNode *b){
        ListNode* nextNode = NULL, *prevNode=NULL, *root;
        int flag = true;
        while(a && b){
            if(a->val <= b->val){
                if(flag)
                    root = a;
                flag = false;
                prevNode = a;
                a = a->next;
            }
            else{
                if(flag)
                    root = b;
                flag = false;
                nextNode = b->next;
                if(prevNode)
                    prevNode->next = b;
                prevNode = b;
                b->next = a;
                b = nextNode;
            }
        }
        if(a)
            prevNode->next = a;
        if(b)
            prevNode->next = b;

        return root;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* root = NULL;

        if(n == 0)
            return root;
        
        int flag = true;
        for(int i=0;i<n;i++){
            if(flag && lists[i]){
                root = lists[i];
                flag = false;
                continue;
            }
            if(lists[i]!=NULL)
                root = MergeLists(root, lists[i]);
        }
        return root;
    }
};