#include <bits/stdc++.h>
struct Node {
    int key, value, count;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        count = 1; 
    }
}; 
struct List {
    int size; 
    Node *head; 
    Node *tail; 
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void add(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void deleteNode(Node* delnode) {
        Node* delp = delnode->prev;
        Node* deln = delnode->next;
        delp->next = deln;
        deln->prev = delp;
        size--; 
    }
    
    
    
};
class LFUCache {
    map<int, Node*> keys; 
    map<int, List*> freq; 
    int size;
    int minm; 
    int curr; 
public:
    LFUCache(int capacity) {
        size = capacity; 
        minm = 0;
        curr = 0; 
    }
    void updateFreqListMap(Node *node) {
        keys.erase(node->key); 
        freq[node->count]->deleteNode(node); 
        if(node->count == minm && freq[node->count]->size == 0) {
            minm++; 
        }
        
        List* nextF = new List();
        if(freq.find(node->count + 1) != freq.end()) {
            nextF = freq[node->count + 1];
        } 
        node->count += 1; 
        nextF->add(node); 
        freq[node->count] = nextF; 
        keys[node->key] = node;
    }
    
    int get(int key) {
        if(keys.find(key) != keys.end()) {
            Node* node = keys[key]; 
            int val = node->value; 
            updateFreqListMap(node); 
            return val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (size == 0) {
            return;
        }
        if(keys.find(key) != keys.end()) {
            Node* node = keys[key]; 
            node->value = value; 
            updateFreqListMap(node); 
        }
        else {
            if(curr == size) {
                List* list = freq[minm]; 
                keys.erase(list->tail->prev->key); 
                freq[minm]->deleteNode(list->tail->prev);
                curr--; 
            }
            curr++; 
            // new value has to be added who is not there previously 
            minm = 1; 
            List* listFreq = new List(); 
            if(freq.find(minm) != freq.end()) {
                listFreq = freq[minm]; 
            }
            Node* node = new Node(key, value); 
            listFreq->add(node);
            keys[key] = node; 
            freq[minm] = listFreq; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
