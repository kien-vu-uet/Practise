#include <bits/stdc++.h>

typedef int unsigned_t;

using namespace std;

unsigned_t partition(vector<unsigned_t> &arr, unsigned_t left, unsigned_t right, unsigned_t key) {
    while (left < right) {
        while (arr[left] < key) left++;
        while (arr[right] > key) right--;
        // cout << left << ": " << arr[left] << " " << key << " " << right << ": " << arr[right] << endl;
        if (left <= right) swap(arr[left], arr[right]);
    }
    return right;
}

void quickSort(vector<unsigned_t> &arr, int left, int right) {
    if (left >= right) return;
    
    unsigned_t key = arr[(left + right) / 2];

    unsigned_t pivot = partition(arr, left, right, key);
    // cout << left << " " << pivot << " " << right <<  endl;

    quickSort(arr, left, pivot);
    quickSort(arr, pivot + 1, right);
}

int main() {
    vector<unsigned_t> a = { -18,66,-51,-28,41,77,60,-2,30,-19,-9,-53,65,-26,-13,-12,-32,3,84,4,-18,-14,15,-46,45,-5,-11,27,-49,-7 };
    map<unsigned_t, unsigned_t> fre;
    vector<unsigned_t> arr;
    for (auto e : a) {
        if (fre[e] == 0) arr.push_back(e);
        fre[e] ++;
    }

    quickSort(arr, 0, arr.size() - 1);

    for (auto element : arr) {
        for (int i = 0; i < fre[element]; i++) {
            cout << element << " ";
        }
    }
    return 0;
}