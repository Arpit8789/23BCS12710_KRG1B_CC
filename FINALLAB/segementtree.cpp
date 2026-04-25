#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int sum;
    int max;
    int min;
};

vector<int> arr = {1, 3, 5, 7, 9, 11};
vector<Node> seg;

Node merge(Node left, Node right) {
    Node res;
    res.sum = left.sum + right.sum;
    res.max = max(left.max, right.max);
    res.min = min(left.min, right.min);
    return res;
}

void build(int idx, int low, int high) {
    if (low == high) {
        seg[idx].sum = arr[low];
        seg[idx].max = arr[low];
        seg[idx].min = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx, low, mid);
    build(2 * idx + 1, mid + 1, high);
    seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
}

Node query(int idx, int low, int high, int l, int r) {
    if (l <= low && high <= r) {
        return seg[idx];
    }
    if (high < l || low > r) {
        Node nullNode;
        nullNode.sum = 0;
        nullNode.max = INT_MIN;
        nullNode.min = INT_MAX;
        return nullNode;
    }
    int mid = (low + high) / 2;
    Node left = query(2 * idx, low, mid, l, r);
    Node right = query(2 * idx + 1, mid + 1, high, l, r);
    return merge(left, right);
}

int main() {
    int n = arr.size();
    seg.resize(4 * n);
    build(1, 0, n - 1);
    
    int l = 2, r = 4;
    Node ans = query(1, 0, n - 1, l, r);
    
    cout << "Sum: " << ans.sum << endl;
    cout << "Max: " << ans.max << endl;
    cout << "Min: " << ans.min << endl;
    
    return 0;
}