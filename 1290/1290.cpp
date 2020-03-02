/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {   
        ListNode* temp = head;
        int res = 0;
        do{
            res = res * 2 + temp->val;          //二进制转十进制
            temp = temp->next;
        }while(temp);
        return res;
    }
};