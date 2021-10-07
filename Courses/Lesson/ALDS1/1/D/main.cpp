#include <iostream>
#include <cmath>
#include <algorithm>
// #include <fstream>

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;

    long long int lg = -(pow(10, 9));
    long long int st;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> st;
        } else {
            long long int tmp;
            cin >> tmp;
            lg = max(lg, tmp - st);
            st = min(st, tmp);
        }
    }

    cout << lg << endl;

    return 0;
}
