class LRUCache {
public:
    class Node{
        public :
        int key , value;
        Node* next;
        Node* prev;

        Node(int key , int value){
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
    };


    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    map<int,Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head ->next = tail;
        tail->prev = head;

    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head; 

        node->next = temp;
        temp->prev = node;
    }
    
    int get(int key) {
        int ans = -1;
        if(mp.find(key) != mp.end()){
            // return mp[key];
            Node* curr = mp[key];
            ans = curr -> value;
            
            deleteNode(curr);
            insertAtHead(curr);
            // mp[key] = ans;
        }
        return ans;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            curr->value = value; 
            deleteNode(curr);
            insertAtHead(curr);
        }
        else{
            Node* newNode = new Node(key, value);
            if(mp.size() == cap){
                Node* todel = tail->prev;
                mp.erase(todel->key);

                deleteNode(tail->prev);
                
                insertAtHead(newNode);
                mp[key]  = newNode;
                delete todel;
            }
            else{
                insertAtHead(newNode);
                mp[key] = newNode;
            }
        }
    }
};
