class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        
        Node* temp = head;

        while (temp) {
            
            for (int i = 1; i < m && temp; i++) {
                temp = temp->next;
            }
    
            
            if (!temp) {
                break;
            }
    
            
            Node* curr = temp->next;
            for (int i = 0; i < n && curr; i++) {
                Node* toDelete = curr;
                curr = curr->next;
                delete toDelete; 
            }
    
            
            temp->next = curr;
    
            
            temp = curr;
        }

    return head;
        
    }
};