#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int length;
    priority_queue<int, vector<int>, greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        length = k;
        for (auto& v:nums)
            add(v);
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > length)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */