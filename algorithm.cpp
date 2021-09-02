## 筛选素数

### 埃氏筛

```cpp
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
```

### 线性筛

```cpp
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        return primes.size();
    }
};

```

## 汉诺塔

```cpp
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);
    }

    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C){
        if (n == 1){
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        move(n-1, A, C, B);    // 将A上面n-1个通过C移到B
        C.push_back(A.back());  // 将A最后一个移到C
        A.pop_back();          // 这时，A空了
        move(n-1, B, A, C);     // 将B上面n-1个通过空的A移到C
    }
};
```

## 二叉树求深度

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left_high = maxDepth(root->left);
        int right_high = maxDepth(root->right);
        if (left_high > right_high)
            return ++left_high;
        else return ++right_high;
    }
};
```

## 洛谷 P1305 [https://www.luogu.com.cn/problem/P1305](https://www.luogu.com.cn/problem/P1305)

### 建立二叉树 输入为节点个数 abc 其中a为父节点，b为左节点，c为右节点

find_node为找到某个字符为x的节点 build为建立该树

```C++
#include <bits/stdc++.h>
using namespace std;

int n;
char root_char, root_left, root_right;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val('0'), left(NULL), right(NULL) {}
    TreeNode(char c) : val(c), left(NULL), right(NULL) {}
};

TreeNode* find_node(TreeNode* root, char c) {
    if (root->val == c)
        return root;
    TreeNode* ret_root = NULL;
    if (root->left)
        ret_root = find_node(root->left, c);
    if (ret_root)
        return ret_root;
    if (root->right)
        ret_root = find_node(root->right, c);
    return ret_root;
}

TreeNode* build(char c) {
    if (c == '*')
        return NULL;
    TreeNode* ret_root = new TreeNode(c);
    return ret_root;
}

void pre_order(TreeNode* root) {
    if (!root)
        return;
    cout << root->val;
    pre_order(root->left);
    pre_order(root->right);
}

int main() {
    cin >> n;
    cin >> root_char >> root_left >> root_right;
    TreeNode* root = new TreeNode(root_char);
    root->left = build(root_left);
    root->right = build(root_right);
    for (int i = 1; i < n; i++) {
        cin >> root_char >> root_left >> root_right;
        TreeNode* cur_node = find_node(root, root_char);
        cur_node->left = build(root_left);
        cur_node->right = build(root_right);
    }
    pre_order(root);
    return 0;
}
```

## leetcode 105 [https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/)

### 已知前序遍历和中序遍历 构建二叉树

这道题关键是在于找到根节点。可以递归的找到根节点

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> _map;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right)
            return nullptr;
        int root_index = preorder_left;
        int inorder_root_index = _map[preorder[root_index]];
        TreeNode* root = new TreeNode(preorder[root_index]);
        int left_tree_node_num = inorder_root_index - inorder_left;
        root->left = build(preorder, inorder, root_index + 1, root_index + left_tree_node_num, inorder_left, inorder_root_index - 1);
        root->right = build(preorder, inorder, root_index + left_tree_node_num + 1, preorder_right, inorder_root_index + 1, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++)
            _map[inorder[i]] = i;
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

```

## 洛谷 P1229 [https://www.luogu.com.cn/problem/P1229](https://www.luogu.com.cn/problem/P1229)

### 已知前序遍历和后续遍历，判断一共能构造出多少种不同的二叉树

这道题的关键在于了解前序遍历和后序遍历为什么能构成不同的二叉树。 经过研究可以发现，只有某一节点A的左右子节点只有一个的时候，才会有两种二叉树（结果要乘2）。而我们如何判断A节点只有一个左节点或右节点呢？根据前序遍历和后序遍历的性质可以得到：当前序遍历是XXXABXXXX后序遍历是XXXBAXXXX时满足该性质，因此在我们遍历的时候要先找到根节点A（pre_order[i] == post_order[j]），对于后续遍历来讲post_order[j - 1]也就是B == 前序遍历的pre_order[i + 1]时才满足该条件。每满足一次该条件，需要对结果乘2

```cpp
#include <bits/stdc++.h>
using namespace std;

string pre_order, post_order;
int ans = 1;

int main() {
    cin >> pre_order >> post_order;
    int n = pre_order.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            if (post_order[j] == pre_order[i] && post_order[j - 1] == pre_order[i + 1])
                ans *= 2;
        }
    }
    cout << ans;
    return 0;
}
```

## 洛谷P4779

[https://www.luogu.com.cn/problem/P4779](https://www.luogu.com.cn/problem/P4779)

dijkstra

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, s, u, v, w;
vector<pair<int, int>> edges[100005];
int dis[100005], vis[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(w, v));
    }
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int now_u = q.top().second;
        q.pop();
        vis[now_u] = 1;
        for (auto& vec:edges[now_u]) {
            int now_v = vec.second, now_w = vec.first;
            if (dis[now_v] > dis[now_u] + now_w) {
                dis[now_v] = dis[now_u] + now_w;
                if (!vis[now_v])
                    q.push(make_pair(dis[now_v], now_v));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    return 0;
}
```

## 快速排序

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[10] = {1, 9, 4, 0, 2, 3, 5, 7};

int qPartition(int left, int right) {
    int i = left, j = right;
    int tmpRecord = a[j];
    while (i != j) {
        while (a[i] <= tmpRecord && j > i)
            i++;
        if (i < j) {
            a[j] = a[i];
            j--;
        }
        while (a[j] >= tmpRecord && j > i)
            j--;
        if (i < j) {
            a[i] = a[j];
            i++;
        }
    }
    a[i] = tmpRecord;
    return i;
}

void quickSort(int left, int right) {
    if (left >= right)
        return;
    int pivot = (left + right) / 2;
    swap(a[pivot], a[right]);
    pivot = qPartition(left, right);
    quickSort(left, pivot - 1);
    quickSort(pivot + 1, right);
}

int main() {
    quickSort(0, 7);
    for (int i = 0; i <= 7; i++)
        cout << a[i] << " ";
    return 0;
}
```

## 最大公约数

求两个数a和b的最大公约数

```cpp
int gcd(int a, int b) {
    return (b==0) ? a : gcd(b, a%b); }
```

## 最小公倍数

求a和b最小公倍数

```cpp
int lcm(int a, int b) {
    return a / gcd(a, b) * b; 
}
```

## sort

降序排列，数组 **sort(a, a + n, greater<int>())**，升序**sort(a, a + n, less<int>())**

vector：sort(a.begin(), a.end())

### 自定义排序

```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<string> a;
string ans;

bool cmp(string cmp_1, string cmp_2) {
    return cmp_1 + cmp_2 >= cmp_2 + cmp_1;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) ans += a[i];
    cout << ans;
    return 0;
}
```

### 01 背包

```c++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e7+5;
int n,m,w[N],v[N],f[M];
signed main(){
	scanf("%lld%lld",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&w[i],&v[i]);
	for(int i=1;i<=n;i++)
		for(int j=w[i];j<=m;j++)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	printf("%lld",f[m]);
	return 0;
}
```

### 逆波兰表达式求值

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> _s;
        for (auto &s:tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int x1 = stoi(_s.top());
                // 头文件为 #include <cstring>
                // stoi是字符串转整数
                // to_string是数字转字符串
                _s.pop();
                int x2 = stoi(_s.top());
                _s.pop();
                if (s == "+")
                    _s.push(to_string(x2 + x1));
                else if (s == "-")
                    _s.push(to_string(x2 - x1));
                else if (s == "*")
                    _s.push(to_string(x2 * x1));
                else if (s == "/")
                    _s.push(to_string(x2 / x1));
            } else _s.push(s);
        }
        return stoi(_s.top());
    }
};
```

