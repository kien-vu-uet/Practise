#include <bits/stdc++.h>

using namespace std;

void shell_sort(vector<int> &a, int left, int right) {
    for (int interval = a.size() / 2; interval > 0; interval /= 2) {
        cout << interval << endl;
        for (int i = left + interval; i <= right; i++) {
            int key = a[i];
            int j;
            for (j = i; j >= interval && a[j - interval] > key; j -= interval) {
                swap(a[j], a[j - interval]);
            }
            a[j] = key;
        }
    }
}

int main() {
    // vector<int> a = { 9,1,6,3,3,1,1,0,3,7,1,6,5,5,4,0,6,9,2,6 }; 
    vector<int> a = { -18,66,-51,-28,41,77,60,-2,30,-19,-9,-53,65,-26,-13,-12,-32,3,84,4,-18,-14,15,-46,45,-5,-11,27,-49,-7 };

    shell_sort(a, 0, a.size() - 1);

    for (auto e : a) {
        cout << e << " ";
    }

    return 0;
}