#include <bits/stdc++.h>

using namespace std;

bool check_front(stack<int> op) {
    if (op.empty()) return false;
    int internal = op.top();
    while (!op.empty()) {
        // cout << op.top() <<" " << internal << endl;
        if (op.top() < internal) return false;
        op.pop();
    } 
    return true;
}

void print_stack(stack<int> op) {
    while (!op.empty()) {
        cout << op.top() << " ";
        op.pop();
    }
    cout << endl;
}

int main() {
    string s = "{{[()[()()]]}}()()[()]";
    cin >> s;

    vector<int> a(s.length());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            a[i] = 1;
        }
        else if (s[i] == ')') {
            a[i] = -1;
        }
        else if (s[i] == '[') {
            a[i] = 2;
        }
        else if (s[i] == ']') {
            a[i] = -2;
        }
        else if (s[i] == '{') {
            a[i] = 3;
        }
        else if (s[i] == '}') {
            a[i] = -3;
        }
    }
    
    stack<int> op;
    bool ok = true;
    
    for (int i = 0; i < a.size() && ok; i++) {
        // cout << a[i];
        if (a[i] > 0) {
            op.push(a[i]);
            ok = check_front(op);
            // cout << " -> push" << endl;
            // print_stack(op);
        }
        else {
            // cout << " -> check couple: ";
            if (op.top() + a[i] != 0) {
                ok = false;
                // cout << "not a couple" << endl;
            }
            // cout << " a couple" << endl;
            op.pop();
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}