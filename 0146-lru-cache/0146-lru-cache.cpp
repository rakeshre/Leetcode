class Node{
    public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int k, int v){
        key=k;
        val=v;//don't keep same name. key as k, val as v.
        next=nullptr;
        prev=nullptr;
    } 
};
class LRUCache {
public:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int capacity;
    unordered_map<int, Node*> mp;
    LRUCache(int cap) {
        this->capacity=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node *v=mp[key];
        remove(v);
        add(v);
        return v->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *ol=mp[key];
            remove(ol);
        }
        Node *n_n=new Node(key,value);
        mp[key]=n_n;
        add(n_n);
        if(mp.size()>capacity){
            Node* to_del=head->next;
            remove(to_del);
            mp.erase(to_del->key);
        }
    }
    
    void add(Node* node){
        Node* prev_end=tail->prev;
        prev_end->next=node;
        node->prev=prev_end;
        node->next=tail;
        tail->prev=node;
    }
    
    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */