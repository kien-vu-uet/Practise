#include <bits/stdc++.h>

using namespace std;

class MergeSort {
public:
    vector<int> merge(vector<int> p1, vector<int> p2) {
        vector<int> res;
        int n = p1.size() + p2.size();
        res.resize(n);
        int i = 0, i1 = 0, i2 = 0;
        while (i < n) {
            if (i1 >= p1.size() && i2 < p2.size()) {
                res[i] = p2[i2];
                ++i;
                ++i2;
            } else if (i1 < p1.size() && i2 >= p2.size()) {
                res[i] = p1[i1];
                ++i;
                ++i1;
            } else if (p1[i1] <= p2[i2]) {
                res[i] = p1[i1];
                ++i;
                ++i1;
            } else if (p1[i1] > p2[i2]) {
                res[i] = p2[i2];
                ++i;
                ++i2;
            }
        } 
        return res;
    }
    
    vector<int> mergeSort(vector<int> a, int left, int right) {
        // divide
        if (left > right) return {};
        if (left == right) {
            vector<int> singleElement = { a[left] };
            return singleElement;
        }
        int mid = (left + right) / 2;
        vector<int> p1 = mergeSort(a, left, mid);
        vector<int> p2 = mergeSort(a, mid + 1, right);
        // merge
        vector<int> res = merge(p1, p2);
        return res;
    }
};

int main() {
    vector<int> a = { 9,1,6,3,3,1,1,0,3,7,1,6,5,5,4,0,6,9,2,6 }; 

    MergeSort* ms = new MergeSort();
    vector<int> r = ms -> mergeSort(a, 0, a.size() - 1);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << " ";
    }
    return 0;
}
