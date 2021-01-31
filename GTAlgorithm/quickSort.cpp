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
    a[i] =tmpRecord;
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