#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5+5;
int arr[maxn];

void quickfind(int *a, int l, int r, int k) {
    int i = l, j = r;
    int pivot = a[l];
    while (i < j) {
        while (i < j && a[j] > pivot) j--;
        if (i < j) { a[i] = a[j]; i++; }
        while (i < j && a[i] < pivot) i++;
        if (i < j) { a[j] = a[i]; j--; }
    }
    a[i] = pivot;
    if (i < k) quickfind(a, i+1, r, k);
    else if (i > k) quickfind(a, l, i-1, k);
    else cout << a[i] << endl;
}

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickfind(arr, 0, n-1, k-1);
    return 0;
}