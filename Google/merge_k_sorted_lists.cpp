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
    ListNode* create_node(int value){
        ListNode* new_node = new ListNode();
        new_node->val = value;      // Assign data to the new node
        new_node->next = nullptr;    // Initialize the next pointer as nullptr
        return new_node;
    }
    void add_node(ListNode*& head, int value) {
        ListNode* temp = create_node(value); // Create a new node
        if (head == nullptr) {
            // If the list is empty, make the new node the head
            head = temp;
        } else {
            // Traverse to the end of the list
            ListNode* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            // Link the last node to the new node
            curr->next = temp;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int , vector<int> , greater<int>> pq;

        

        for(ListNode* list : lists){

            while(list != NULL){
                pq.push(list->val);
                list = list ->next;
            }
        }

        ListNode* head = NULL;
        // pq.pop();
        while(!pq.empty()){
            
            add_node(head,pq.top());
            pq.pop();
        }
        return head;
    }
};