#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

int n;
vector<int> v;

bool solve(int i, int m) {
    if (m == 0) {
        return true;
    }
    if (i >= n) {
        return false;
    }
    return solve(i + 1, m) || solve(i + 1, m - v[i]);
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        if (solve(0, m)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
