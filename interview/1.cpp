#include <iostream>
using namespace std;

// {1,6,7,8},{2,3,4,5}

const int maxn = 10005;
int arr1[maxn];
int arr2[maxn];

int n;

int func() {
    int l = 0, r = n - 1;
    int mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (arr1[mid] < arr2[n - mid - 1] && arr1[mid+1] < arr2[n-mid-2]) {
            l = mid + 1;
        }
        else if (arr1[mid] < arr2[n-mid-1] && arr1[mid+1] > arr2[n-mid-2]) {
            if (arr1[mid] < arr2[n-mid-2]) return arr2[n-mid-2];
            else return arr1[mid];
        }
        else if (arr1[mid] > arr2[n-mid-1]) {
            r = mid;
        }
    }
    // l == r
    if (arr1[l] < arr2[n-l-1]) return arr1[l];
    else return arr2[n-l-1];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    cout << func() << endl;
    return 0;
}