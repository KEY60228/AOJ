#include <iostream>
#include <vector>
// #include <fstream>

#define CENTINEL 2000000000

using namespace std;

vector<pair<char, long long int>> vs;
vector<pair<char, long long int>> vm;

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<pair<char, long long int>> L, R;
    for (int i = 0; i < n1; i++) {
        L.push_back(vm[left + i]);
    }
    L.push_back({'Z', CENTINEL});
    for (int i = 0; i < n2; i++) {
        R.push_back(vm[mid + i]);
    }
    R.push_back({'Z', CENTINEL});

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].second <= R[j].second) {
            vm[k] = L[i];
            i++;
        } else {
            vm[k] = R[j];
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

int partition(int p, int r) {
    int x = vs[r].second;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (vs[j].second <= x) {
            i++;
            pair<char, long long int> tmp = vs[i];
            vs[i] = vs[j];
            vs[j] = tmp;
        }
    }
    pair<char, long long int> tmp = vs[i + 1];
    vs[i + 1] = vs[r];
    vs[r] = tmp;
    return i + 1;
}

void quickSort(int p, int r) {
    if (p < r) {
        int q = partition(p, r);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    long long int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        char b;
        cin >> b >> a;
        vs.push_back({b, a});
        vm.push_back({b, a});
    }

    quickSort(0, n - 1);
    mergeSort(0, n);

    bool flg = true;
    for (int i = 0; i < n; i++) {
        if (vs[i].first != vm[i].first) {
            flg = false;
        }
    }

    if (flg) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << vs[i].first << " " << vs[i].second << endl;
    }

    return 0;
}