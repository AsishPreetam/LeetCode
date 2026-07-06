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
    void Reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
    }
    ListNode* findKthNode(ListNode* temp, int k){
        k = k - 1;
        while(temp!=nullptr && k>0){
            k--;
            temp  = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while(temp!=nullptr){
            ListNode* KthNode = findKthNode(temp, k);
            if(KthNode==nullptr){
                if(prevNode!=nullptr)
                prevNode->next = temp;
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = nullptr;
            Reverse(temp);
            if(temp==head){
                head = KthNode;
            }
            else{
                prevNode->next = KthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

/*
Time complexity: O(n);
Space complexity: O(1);
*/
