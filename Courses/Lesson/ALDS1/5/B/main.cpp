#include <iostream>
#include <vector>
#include <limits>
// #include <fstream>

#define CENTINEL 2000000000

using namespace std;

long long int cnt = 0;
vector<long long int> v;

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<long long int> L, R;
    for (int i = 0; i < n1; i++) {
        L.push_back(v[left + i]);
    }
    L.push_back(CENTINEL);
    for (int i = 0; i < n2; i++) {
        R.push_back(v[mid + i]);
    }
    R.push_back(CENTINEL);

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    mergeSort(0, n);

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
