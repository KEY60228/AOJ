#include <iostream>
// #include <fstream>

using namespace std;

int gcd(int x, int y) {
    if (x < y) {
        swap(x, y);
    }

    int r;
    while (y > 0) {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}
