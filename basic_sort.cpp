#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &a, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = a[i];
        int j;
        for (j = i - 1; j >= left; j--) {
            if (a[j] > key) a[j + 1] = a[j];
            else break;
        }
        a[j + 1] = key;
    }
}

void selection_sort(vector<int> &a, int left, int right) {
    for (int i = left; i <= right; i++) {
        int min = i;
        for (int j = i + 1; j <= right; j++) {
            if (a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}

void buble_sort(vector<int> &a, int left, int right) {
    for (int i = left; i <= right; i++) {
        bool swapped = false;
        for (int j = left; j < right; j++) {
            if (a[j] > a[j+ 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    vector<int> a = { 9, 6, 4, 5, 2, 7, 1, 3 };

    // insertion_sort(a, 1, a.size() - 2);
    // selection_sort(a, 1, a.size() - 2);
    buble_sort(a, 1, a.size() - 2);

    for (auto e : a) {
        cout << e << " ";
    }

    return 0;
}