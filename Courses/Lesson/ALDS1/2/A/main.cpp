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
    while (true) {
        bool flg = false;
        for (int i = n - 1; i > 0; i--) {
            if (v[i] < v[i - 1]) {
                int tmp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = tmp;
                flg = true;
                count++;
            }
        }
        if (!flg) {
            break;
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
