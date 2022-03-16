#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

#define MAX 100000

using namespace std;

int lis(int n, vector<int> A) {
    vector<int> L;
    L.push_back(A[0]);
    int length = 1;

    for (int i = 1; i < n; i++) {
        if (L[length - 1] < A[i]) {
            length++;
            L.push_back(A[i]);
        } else {
            *lower_bound(L.begin(), L.end(), A[i]) = A[i];
        }
    }

    return length;
}

void solve(int n, vector<int> A) {
    cout << lis(n, A) << endl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    vector<int> A(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    solve(n, A);

    return 0;
}
