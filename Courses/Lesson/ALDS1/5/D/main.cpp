#include <iostream>
#include <vector>
// #include <fstream>

#define CENTINEL 2000000000

using namespace std;

vector<long long int> A;

long long int merge(int n, int left, int mid, int right) {
    long long int cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    vector<long long int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L.push_back(CENTINEL);
    R.push_back(CENTINEL);

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            cnt += n1 - i; // = mid + j - k - 1
        }
    }

    return cnt;
}

long long int mergeSort(int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        long long int v1 = mergeSort(n, left, mid);
        long long int v2 = mergeSort(n, mid, right);
        long long int v3 = merge(n, left, mid, right);
        return v1 + v2 + v3;
    } else {
        return 0;
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
        A.push_back(tmp);
    }

    long long int ans = mergeSort(n, 0, n);

    cout << ans << endl;

    return 0;
}
