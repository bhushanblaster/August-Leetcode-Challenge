/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

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
    void reorderList(ListNode* head) {
         
        vector<ListNode*>nodes;
        ListNode* temp = head; 
        while(temp)
        {
            nodes.push_back(temp);
            temp = temp->next;
        }
        int sz = nodes.size();
        if(sz<=1)
            return;
        int i,j;
        int mid = sz/2;
        if(mid*2 == sz)
        {
            head = nodes[mid-1]; 
            nodes[mid-1] = nodes[mid];
            nodes[mid]->next = NULL;
            i = mid-2;
            j = mid+1;
            
        }
        else
        {
            head = nodes[mid];
            head->next = NULL;
            i = mid-1;
            j = mid+1;
        }  
        while(i>=0)
        {
            temp = head;
            head = nodes[i];
            nodes[i]->next = nodes[j];
             nodes[j]->next = temp;
               i--;j++; 
        }
    }
};
