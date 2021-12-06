#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    vector<int> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<int> C(10001, 0);

    for (int i = 1; i <= n; i++) {
        C[A[i]]++;
    }

    for (int i = 1; i <= 10001; i++) {
        C[i] += C[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << B[i];
    }
    cout << endl;

    return 0;
}
