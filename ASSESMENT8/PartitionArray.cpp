#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int max_val = 0;
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                max_val = max(max_val, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + max_val * j);
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << "Output: " << sol.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}
