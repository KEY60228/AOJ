#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

int n, k;
vector<int> v;

int check(long long int P) {
    int i = 0;
    for (int j = 0; j < k; j++) {
        long long int s = 0;
        while (s + v[i] <= P) {
            s += v[i];
            i++;
            if (i == n) {
                return n;
            }
        }
    }
    return i;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    long long int left = 0;
    long long int right = 100000 * 10000;
    long long int mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        int v = check(mid);
        if (v >= n) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;

    return 0;
}