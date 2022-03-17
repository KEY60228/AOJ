#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

int getLargestSquare(vector<vector<int>> v) {
    int maxWidth = 0;

    vector<vector<int>> dp(v.size(), vector<int>(v[0].size()));
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            dp[i][j] = (v[i][j] + 1) % 2;
            if (maxWidth != 1 && dp[i][j] != 1) {
                maxWidth = 0;
            } else {
                maxWidth = 1;
            }
        }
    }

    for (int i = 1; i < v.size(); i++) {
        for (int j = 1; j < v[i].size(); j++) {
            if (v[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxWidth = max(maxWidth, dp[i][j]);
            }
        }
    }

    return maxWidth * maxWidth;
}

void solve(vector<vector<int>> v) {
    cout << getLargestSquare(v) << endl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int h, w;
    cin >> h >> w;

    vector<vector<int>> v(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    }
    solve(v);

    return 0;
}
