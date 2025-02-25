class LRUCache {
public:
    class Node{
        public:
            int key, value;
            Node* prev;
            Node* next;
        Node(int key, int val){
            this->key = key;
            this->value = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mpp;

    // Functionality needed
    void addNodeFront(Node* newNode){
        Node* temp = head->next;
        temp->prev = newNode;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
    }

    void deleteNode(Node* delNode){
        Node* ahead = delNode->prev;
        Node* last = delNode->next;
        ahead->next = last;
        last->prev = ahead;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* curr = mpp[key];
            int ans = curr->value;
            mpp.erase(key);
            deleteNode(curr);
            addNodeFront(curr);
            mpp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* existedNode = mpp[key];
            mpp.erase(key);
            deleteNode(existedNode);
        }
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNodeFront(new Node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */