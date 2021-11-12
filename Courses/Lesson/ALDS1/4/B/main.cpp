#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    int q;
    cin >> q;

    int count = 0;
    for (int i = 0; i < q; i++) {
        int C;
        cin >> C;
        if (binary_search(S.begin(), S.end(), C)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
