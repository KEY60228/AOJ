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

    for (int i = 0; i < n; i++) {
        int s = v[i];
        for (int j = i - 1; j >= 0; j--) {
            if (s < v[j]) {
                v[j + 1] = v[j];
                v[j] = s;
            } else {
                v[j + 1] = s;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            cout << v[j];
            if (j != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
