#include <iostream>
#include <map>
#include <functional>
// #include <fstream>

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    map<size_t, string> mp;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        if (s == "insert") {
            mp[hash<string>()(t)] = t;
        } else {
            if (mp[hash<string>()(t)] == t) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}