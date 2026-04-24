// Experiment 10: Count of Smaller Numbers After Self
// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
// Example: nums = [5,2,6,1] -> Output: [2,1,1,0]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = {nums[i], i};
        mergeSort(arr, 0, n - 1, counts);
        return counts;
    }
private:
    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& counts) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid + 1, right, counts);
        merge(arr, left, mid, right, counts);
    }
    void merge(vector<pair<int, int>>& arr, int left, int mid, int right, vector<int>& counts) {
        int n1 = mid - left + 1, n2 = right - mid;
        vector<pair<int, int>> L(n1), R(n2);
        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
        for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];
        int i = 0, j = 0, k = left, rightCount = 0;
        while (i < n1 && j < n2) {
            if (L[i].first <= R[j].first) {
                counts[L[i].second] += rightCount;
                arr[k++] = L[i++];
            } else {
                rightCount++;
                arr[k++] = R[j++];
            }
        }
        while (i < n1) {
            counts[L[i].second] += rightCount;
            arr[k++] = L[i++];
        }
        while (j < n2) arr[k++] = R[j++];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {5,2,6,1},
        {-1},
        {-1,-1}
    };
    for (auto& nums : testCases) {
        vector<int> result = sol.countSmaller(nums);
        cout << "Input: [";
        for (int i = 0; i < nums.size(); ++i) cout << nums[i] << (i+1==nums.size()?"":", ");
        cout << "]\nOutput: [";
        for (int i = 0; i < result.size(); ++i) cout << result[i] << (i+1==result.size()?"":", ");
        cout << "]\n";
    }
    return 0;
}
