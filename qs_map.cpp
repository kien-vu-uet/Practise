#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int left, int right, int key) {
    while (left < right) {
        while (a[left] < key) left++;
        while (a[right] > key) right--;
        if (left <= right) swap(a[left], a[right]);
    }
    return right;
}

void quick_sort(vector<int> &a, int left, int right) {
    if (left >= right) return;

    int key = a[(left + right) / 2];

    int pivot = partition(a, left, right, key);

    quick_sort(a, left, pivot);
    quick_sort(a, pivot + 1, right);
}

void qs_map(map<int, int>::iterator begin, map<int, int>::iterator end) {
    vector<int> a;
    map<int, int> fre;
    for (map<int, int>::iterator it = begin; it != end; it++) {
        int e = it -> second;
        if (fre[e] == 0) a.push_back(e);
        fre[e]++;
    }
    quick_sort(a, 0, a.size() - 1);
    int i = 0;
    map<int, int>::iterator it = begin;
    for (int i = 0; i < a.size() && it != end; i++) {
        for (int j = 0; j < fre[a[i]] && it != end; j++, it++) {
            it -> second = a[i];
        }
    }
}

int main() {
    vector<int> a = { 1,2,3,0,-4,2,4,2,-4,-6,-3,-2,10,0,1 };
    map<int, int> pst;
    map<int, int> ngt;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > 0) pst[i] = a[i];
        else if (a[i] < 0) ngt[i] = -a[i];
    }

    qs_map(pst.begin(), pst.end());
    qs_map(ngt.begin(), ngt.end());

    for (map<int, int>::iterator it = pst.begin(); it != pst.end(); ++it) {
        int key = it -> first;
        int value = it -> second;
        a[key] = value;
    }

    for (map<int, int>::iterator it = ngt.begin(); it != ngt.end(); ++it) {
        int key = it -> first;
        int value = it -> second;
        a[key] = -value;
    }

    for (auto e : a) {
        cout << e << " ";
    }

    return 0;
}