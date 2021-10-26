#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    string s;

    stack<int> st;
    while (cin >> s) {
        if (s == "+") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b + a);
        } else if (s == "-") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b - a);
        } else if (s == "*") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b * a);
        } else {
            st.push(stoi(s));
        }
    }

    cout << st.top() << endl;

    return 0;
}
