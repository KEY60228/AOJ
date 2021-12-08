#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

using namespace std;

int n;
int s = 10000;
vector<int> A;

int solve() {
    int ans = 0;

    vector<bool> V(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
        V[i] = false;
    }
    vector<int> T(10001);
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++) {
        T[B[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (V[i]) continue;
        int cur = i;
        int S = 0;
        int m = 10000;
        int an = 0;
        while (true) {
            V[cur] = true;
            an++;
            int v = A[cur];
            m = min(m, v);
            S += v;
            cur = T[v];
            if (V[cur]) break;
        }
        ans += min(S + (an - 2) * m, m + S + (an + 1) * s);
    }

    return ans;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
        s = min(s, tmp);
    }

    int ans = solve();

    cout << ans << endl;

    return 0;
}