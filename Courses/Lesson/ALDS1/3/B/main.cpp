#include <iostream>
#include <queue>
#include <string>
// #include <fstream>

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    long long int n, q;
    cin >> n >> q;

    queue<pair<string, long long int>> que;
    for (int i = 0; i < n; i++) {
        pair<string, long long int> p;
        cin >> p.first >> p.second;
        que.push(p);
    }

    vector<pair<string, long long int>> v;
    long long int t = 0;
    while (!que.empty()) {
        pair<string, long long int> p = que.front();
        que.pop();

        if (p.second <= q) {
            pair<string, long long int> tmp{p.first, t + p.second};
            v.push_back(tmp);
            t += p.second;
        } else {
            p.second -= q;
            que.push(p);
            t += q;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
