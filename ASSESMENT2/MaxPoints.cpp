#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    int get_gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int max_pts = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slope_counts;
            int same_points = 1;
            int max_slopes = 0;
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    same_points++;
                } else {
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    int g = get_gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                    if (dx < 0 || (dx == 0 && dy < 0)) {
                        dx = -dx;
                        dy = -dy;
                    }
                    string slope = to_string(dx) + "_" + to_string(dy);
                    slope_counts[slope]++;
                    max_slopes = max(max_slopes, slope_counts[slope]);
                }
            }
            max_pts = max(max_pts, max_slopes + same_points);
        }
        return max_pts;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    cout << "Output: " << sol.maxPoints(points) << endl;
    return 0;
}
