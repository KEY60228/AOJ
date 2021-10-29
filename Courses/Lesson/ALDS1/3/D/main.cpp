#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    stack<int> st;
    stack<pair<int, int>> st2;
    char c;
    for (int i = 0; cin >> c; i++) {
        if (c == '\\') {
            st.push(i);
        } else if (c == '/' && st.size()) {
            int j = st.top();
            st.pop();
            int m = i - j;
            while (st2.size() && st2.top().first > j) {
                m += st2.top().second;
                st2.pop();
            }
            st2.push({j, m});
        }
    }

    vector<int> v;
    while (st2.size()) {
        v.push_back(st2.top().second);
        st2.pop();
    }
    reverse(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    cout << sum << endl;
    cout << v.size();
    for (int i = 0; i < v.size(); i++) {
        cout << " ";
        cout << v[i];
    }
    cout << endl;

    return 0;
}
