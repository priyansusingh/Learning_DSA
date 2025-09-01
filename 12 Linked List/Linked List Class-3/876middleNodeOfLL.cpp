#include<iostream>
using namespace std;

struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 // leetcode 876: Middle of the Linked List
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            //fast ko 1 step aage kro
            fast = fast->next;
            // check if fast is on NULL 
            if(fast!=NULL){
                fast=fast->next;
                // fast ke 2 step ho chuke hai
                slow=slow->next;
            }
        }
        return slow;
    }
};