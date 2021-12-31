#include <iostream>
#include <vector>
// #include <fstream>

#define ll long long int
#define MAX 2000000
#define INFTY (1<<30)

using namespace std;

int H;
vector<int> A(MAX + 1);

void maxHeapify(int i) {
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    if (l <= H && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r <= H && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int extract() {
    int maxv;
    if (H < 1) return -INFTY;
    maxv = A[1];
    A[1] = A[H--];
    maxHeapify(1);
    return maxv;
}

void increaseKey(int i, int key) {
    if (key < A[i]) return;
    A[i] = key;
    while (i > 1 && A[i / 2] < A[i]) {
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

void insert(int key) {
    H++;
    A[H] = -INFTY;
    increaseKey(H, key);
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    while (true) {
        int key;
        string com;
        cin >> com;
        if (com == "end") break;
        if (com == "insert") {
            cin >> key;
            insert(key);
        } else {
            cout << extract() << endl;
        }
    }

    return 0;
}
