#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool check(int, long long int, long long int);

int main() {
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    int n, k;
    cin >> n >> k;

    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    cout << sum << endl;

    long long int left = 0;
    long long int right = 100000 * 10000;
    long long int mid;
    while(right - left > 1) {
        if (check(k, mid, sum)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;

    return 0;
}

bool check(int k, long long int p, long long int sum) {
    return k * p >= sum;
}
