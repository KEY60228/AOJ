#include <iostream>
#include <list>
// #include <fstream>

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    long long int n;
    cin >> n;

    list<long long int> l;
    for (long long int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "insert") {
            long long int d;
            cin >> d;
            l.push_front(d);
        }
        if (s == "delete") {
            long long int d;
            cin >> d;
            for (auto itr = l.begin(); itr != l.end(); itr++) {
                if (*itr == d) {
                    l.erase(itr);
                    break;
                }
            }
        }
        if (s == "deleteFirst") {
            l.pop_front();
        }
        if (s == "deleteLast") {
            l.pop_back();
        }
    }

    for (auto itr = l.begin(); itr != l.end(); itr++) {
        if (itr != l.begin()) {
            cout << " ";
        }
        cout << *itr;
    }
    cout << endl;

    return 0;
}
