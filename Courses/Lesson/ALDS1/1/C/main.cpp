#include <iostream>
// #include <fstream>

using namespace std;

bool isPrime(int x) {
    if (x < 2) {
        return false;
    } else if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (isPrime(x)) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}