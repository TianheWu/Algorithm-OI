#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> v;
    int base = 1000;
    int hash(int key) {
        return key % base;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        v.resize(base);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = hash(key);
        for (auto p = v[idx].begin(); p != v[idx].end(); p++) {
            if (p->first == key) {
                p->second = value;
                return;
            }
        }
        v[idx].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = hash(key);
        for (auto p = v[idx].begin(); p != v[idx].end(); p++) {
            if (p->first == key) {
                return p->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = hash(key);
        for (auto p = v[idx].begin(); p != v[idx].end(); p++) {
            if (p->first == key) {
                v[idx].erase(p);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */