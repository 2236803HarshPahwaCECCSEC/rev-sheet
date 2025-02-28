class LRUCache {
    struct Node{
        int key,value;
        Node* prev,*next;
        Node(int k,int v){
            key=k;
            value=v;
            prev=nullptr;
            next=nullptr;
        }
    };
    int capacity;
    unordered_map<int,Node*> cache;
    Node *head,*tail;//dummy nodes;
    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insertatHead(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void movetoHead(Node* node){
        removeNode(node);
        insertatHead(node);
    }
public:
    LRUCache(int cap):capacity(cap) {
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        Node* newNode=cache[key];
        movetoHead(newNode);
        return newNode->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* node=cache[key];
            node->value=value;
            movetoHead(node);
        }else{
            if(cache.size()==capacity){
                Node* lru=tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
                    Node* newNode=new Node(key,value);
        cache[key]=newNode;
        insertatHead(newNode);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */