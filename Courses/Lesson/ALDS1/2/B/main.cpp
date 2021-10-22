#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (v[minj] > v[j]) {
                minj = j;
            }
        }
        if (v[i] != v[minj]) {
            int tmp = v[i];
            v[i] = v[minj];
            v[minj] = tmp;
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
