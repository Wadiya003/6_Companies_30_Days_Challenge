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
    ListNode* removeZeroSumSublists(ListNode* head) {
             
        ListNode* prehead =new ListNode(0);
        prehead->next=head;
        unordered_map<int,ListNode*>m;
        m[0]=prehead;
        int val=0;
        while(head!=NULL){
            val+=head->val;
            if(m.find(val)!=m.end()){
                ListNode* pre= m[val];
                ListNode* connect= pre;

                int aux = val;
                while(pre!=head){
                    pre=pre->next;
                    aux+=pre->val;
                    if(pre!=head)m.erase(aux);
                }
                
                connect->next = head->next;
            }else{
                m[val]= head;
            }
            
            head=head->next;
        }
        
        return prehead->next;
    }
};