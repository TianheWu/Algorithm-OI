#include <bits/stdc++.h>
using namespace std;

/*  Problem: Batch job scheduling problem

    There are n workpieces that need to be processed on machines M1 and M2, 
    and the processing sequence of each workpiece is first processed on M1, and then processed on M2. 

    t1j, t2j respectively represent the processing time required for workpiece j on M1 and M2 (j=1, 2, ···, n). 
    How to arrange production on the two machines so that the total processing time 
    required for the first workpiece to be processed on M1 to the last workpiece to be processed on M2 is the shortest?

*/

struct Node {
    int t1, t2, di, idx;
};

int N, max_1, max_2;
Node f[1005];

bool cmp(Node a, Node b) {
    if (a.di < b.di)
        return true;
    else if (a.di == b.di) {
        if (a.di <= 0) 
            return a.t1 < b.t1;
        else return a.t2 > b.t2;
    } 
    else return false;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) 
        cin >> f[i].t1;
    for (int i = 1; i <= N; i++) {
        cin >> f[i].t2;
        if (f[i].t1 == f[i].t2)
            f[i].di = 0;
        else f[i].di = f[i].t1 > f[i].t2 ? 1 : -1;
        f[i].idx = i;
    }
    sort(f + 1, f + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
        if (i != 1)
            max_1 += f[i].t1;
        if (i != N)
            max_2 += f[i].t2;
    }
    cout << "The min time we need is " << max(max_1, max_2) + f[1].t1 + f[N].t2 << endl;
    cout << "The processing sequence is: ";
    for (int i = 1; i <= N; i++)
        cout << f[i].idx << " ";
    return 0;
}