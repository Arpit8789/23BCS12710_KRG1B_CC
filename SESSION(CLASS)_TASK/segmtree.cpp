#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> seg;
vector<int> lazy;

void build(int ind, int low, int high) {
    if (low == high) {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void push(int ind, int low, int high) {
    if (lazy[ind] != 0) {
        seg[ind] += lazy[ind];
        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
}

void updateRange(int ind, int low, int high, int l, int r, int val) {
    push(ind, low, high);

    if (r < low || high < l) {
        return;
    }
    if (l <= low && high <= r) {
        lazy[ind] += val;
        push(ind, low, high);
        return;
    }

    int mid = (low + high) / 2;
    updateRange(2 * ind + 1, low, mid, l, r, val);
    updateRange(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r) {
    push(ind, low, high);

    if (r < low || high < l) {
        return INT_MIN;
    }
    if (l <= low && high <= r) {
        return seg[ind];
    }
    int mid = (low + high) / 2;
    int leftAns = query(2 * ind + 1, low, mid, l, r);
    int rightAns = query(2 * ind + 2, mid + 1, high, l, r);
    return max(leftAns, rightAns);
}

int main() {
    arr = {3, 7, 9, 12, 15, 16, 5, 2, 19, 21};
    int n = arr.size();
    seg.assign(4 * n, 0);
    lazy.assign(4 * n, 0);

    build(0, 0, n - 1);

    cout << "Initial max in range [1,3] = " << query(0, 0, n - 1, 1, 3) << '\n';
    cout << "Initial max in range [7,9] = " << query(0, 0, n - 1, 7, 9) << '\n';

    updateRange(0, 0, n - 1, 2, 5, 4);
    cout << "After adding 4 to range [2,5], max in [1,3] = " << query(0, 0, n - 1, 1, 3) << '\n';
    cout << "After adding 4 to range [2,5], max in [7,9] = " << query(0, 0, n - 1, 7, 9) << '\n';

    return 0;
}
