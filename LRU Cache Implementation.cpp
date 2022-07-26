#include <bits/stdc++.h>
class LRUCache
{
public:
    class Node {
        public :
        int key, value;
        Node* prev, *next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int size;
    map<int, Node*> m;
    
    void add(int key, int value) {
        Node* temp = new Node(key, value);
        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
    }
    
    void deleteNode(Node* temp) {
        Node* t = temp->prev;
        t->next = t->next->next;
        temp->next->prev = t;
        delete temp;
    }
    
    LRUCache(int capacity)
    {
       size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if(m.find(key) == m.end()) return -1;
        int value = m[key]->value;
        deleteNode(m[key]);
        add(key, value);
        m[key] = head->next;
        return value;
    }

    void put(int key, int value)
    {
        if(m.find(key) != m.end()) {
            deleteNode(m[key]);
            add(key, value);
            m[key] = head->next;
            return;
        }
        if(m.size() == size) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
            add(key, value);
            m[key] = head->next;
    }
};
