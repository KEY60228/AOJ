#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

#define NMAX 105
#define WMAX 10005

using namespace std;

struct Item {
    int value;
    int weight;
};

int compute(int n, int w, vector<Item> items) {
    vector<vector<int>> C(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            C[i][j] = C[i - 1][j];
            if (items[i].weight > j) continue;
            if (items[i].value + C[i - 1][j - items[i].weight] > C[i - 1][j]) {
                C[i][j] = items[i].value + C[i - 1][j - items[i].weight];
            }
        }
    }

    return C[n][w];
}

void solve(int n, int w, vector<Item> items) {
    cout << compute(n, w, items) << endl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n, w;
    cin >> n >> w;

    vector<Item> items(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    solve(n, w, items);

    return 0;
}
