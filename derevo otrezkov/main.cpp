#include <iostream>

using namespace std;

struct tree {
    long *tr;

    tree(int n) {
        tr = new long[4 * n + 1];
    }

    void build(int *arr, int v, int l, int r) {
        if (l == r) tr[v] = arr[l];
        else {
            int mid = (l + r) / 2;
            build(arr, v * 2, l, mid);
            build(arr, v * 2 + 1, mid + 1, r);
            tr[v] = tr[v * 2] + tr[v * 2 + 1];
        }
    }

    void update(int v, int l, int r, int pos, int val) {
        if (l == r) tr[v] = val;
        else {
            int mid = (l + r) / 2;
            if (pos <= mid) update(v * 2, l, mid, pos, val);
            else update(v * 2 + 1, mid + 1, r, pos, val);
            tr[v] = tr[v * 2] + tr[v * 2 + 1];
        }
    }

    int find(int v, int l, int r, int max) {
        if (l == r)
            return (tr[v] <= max);
        int mid = (l + r) / 2;
        if (tr[v * 2] > max)
            return find(v * 2, l, mid, max);
        else
            return mid - l + 1 + find(v * 2 + 1, mid + 1, r, max - tr[v * 2]);
    }
};

int main() {
    int n, *arr;
    cin >> n;
    arr = new int[n + 1];
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    tree tr(n);
    tr.build(arr, 1, 1, n);
    int v;
    cin >> v;
    cout << tr.find(1, 1, n, v) << '\n';
    return 0;
}