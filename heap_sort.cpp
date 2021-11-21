#include <bits/stdc++.h>

using namespace std;

void shift_down(vector<int> &a, int pos, int right);
void heap_sort(vector<int> &a, int right);
void print(vector<int> a, int right);

int main() {
    vector<int> a = { 5, 4, 6, 2, 7, 8, 1, 0, 9, 3 };

    heap_sort(a, a.size() - 1);

    for (auto e : a) {
        cout << e << " ";
    }

    return 0;
}

void shift_down(vector<int> &a, int pos, int right) {
    int max = pos;
    int l = pos * 2 + 1;
    int r = pos * 2 + 2;

    if (l <= right && a[l] > a[max]) max = l;
    if (r <= right && a[r] > a[max]) max = r;

    if (max != pos) {
        swap(a[max], a[pos]);
        shift_down(a, max, right);
    }
}

void heap_sort(vector<int> &a, int right) {
    if (right < 0) return;
    
    int mid = (right - 1) / 2;
    
    // build a max heap tree
    for (int i = mid; i >= 0; i--) {
        shift_down(a, i, right);
    }

    // get root
    swap(a[right], a[0]);

    // continue with a new tree
    heap_sort(a, right - 1);
}

void print(vector<int> a, int right) {
    for (int i = 0; i <= (right - 1) / 2; i++) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        cout << a[i] << " ";
        if (l <= right) cout << "[ " << a[l];
        if (r <= right) cout << " , " << a[r];
        cout << " ]" << endl;
    }
    cout << "======================" << endl;
}