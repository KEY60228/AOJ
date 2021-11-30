#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

vector<int> v;

int partition(int p, int r) {
    int x = v[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (v[j] <= x) {
            i++;
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
    }
    int tmp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = tmp;
    return i + 1;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int ind = partition(0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        if (i == ind) {
            cout << "[" << v[i] << "]";
        } else {
            cout << v[i];
        }
    }
    cout << endl;

    return 0;
}
