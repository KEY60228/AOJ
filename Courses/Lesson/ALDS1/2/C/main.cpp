#include <iostream>
#include <vector>
#include <string>
// #include <fstream>

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;

    vector<pair<char, int>> v(n), v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        v2[i] = v[i];
    }

    // Bubble Sort
    while (true) {
        bool flg =  false;
        for (int i = n - 1; i > 0; i--) {
            if (v[i].second < v[i - 1].second) {
                pair<char, int> tmp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = tmp;
                flg = true;
            }
        }
        if (!flg) {
            break;
        }
    }

    // Selection Sort
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (v2[minj].second > v2[j].second) {
                minj = j;
            }
        }
        if (i != minj) {
            pair<char, int> tmp = v2[minj];
            v2[minj] = v2[i];
            v2[i] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i].first << v[i].second;
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    cout << "Stable" << endl;

    bool flg = true;
    for (int i = 0; i < n; i++) {
        if (v[i].first != v2[i].first || v[i].second != v[i].second) {
            flg = false;
        }
        cout << v2[i].first << v2[i].second;
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    if (flg) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    return 0;
}
