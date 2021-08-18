// Hashtable and Doublly LinkedList is used;

class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node(int key1,int val1){            // calling constructor
            key = key1;
            val = val1;
        }
    };
public:
    void addnode(Node *currentNode){
        currentNode->next = head->next;
        currentNode->prev = head;
        head->next = currentNode;
        currentNode->next->prev = currentNode;
    }
    
    void deletenode(Node *currentNode){
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
    }
    
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    
    LRUCache(int capacity) {                // Constructor called
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    unordered_map<int,Node*> m;
    
    int get(int key2) {
        if(m.find(key2) != m.end()){
            Node* resnode = m[key2];
            int res = resnode->val;
            m.erase(key2);
            deletenode(resnode);
            addnode(resnode);
            m[key2] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key3, int value3) {
        if(m.find(key3) != m.end()){
            Node* resnode = m[key3];
            deletenode(resnode);
            m.erase(key3);
        }
        
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new Node(key3,value3));
        m[key3] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
