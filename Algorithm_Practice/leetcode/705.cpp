#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    vector<list<int>> v;
    int base = 1000;
    int hash(int key) {
        return key % base;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        v.resize(base);
    }
    
    void add(int key) {
        int idx = hash(key);
        for (auto p = v[idx].begin(); p != v[idx].end(); p++) {
            if ((*p) == key)
                return;
        }
        v[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        for (auto p = v[idx].begin(); p != v[idx].end(); p++) {
            if ((*p) == key) {
                v[idx].erase(p);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = hash(key);
        for (auto p = v[idx].begin(); p != v[idx].end(); p++) {
            if ((*p) == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */