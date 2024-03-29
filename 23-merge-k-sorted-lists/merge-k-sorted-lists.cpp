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
    class Comparator {
    public : 
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , Comparator>minHeap;
        for(int i=0 ; i<lists.size() ; i++){
            if(lists[i] != NULL)minHeap.push(lists[i]);
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(!minHeap.empty()){
            ListNode* top = minHeap.top();
            minHeap.pop();
            if(top->next != NULL){
                minHeap.push(top->next);
            }
            if(head == nullptr){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};