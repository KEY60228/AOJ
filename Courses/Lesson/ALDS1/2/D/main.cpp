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

    vector<int> vi;
    int h = 1;
    while (true) {
        if (h > n) {
            break;
        }
        vi.push_back(h);
        h = 3 * h + 1;
    }

    for (int i = vi.size() - 1; i >= 0; i--) {
        for (int j = vi[i]; j < n; j++) {
            int si = v[j];
            for (int k = j - vi[i]; k >= 0; k -= vi[i]) {
                if (si < v[k]) {
                    v[k + vi[i]] = v[k];
                    v[k] = si;
                    count++;
                } else {
                    break;
                }
            }
        }
    }

    cout << vi.size() << endl;
    for (int i = vi.size() - 1; i >= 0; i--) {
        cout << vi[i];
        if (i != 0) {
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }

    return 0;
}
