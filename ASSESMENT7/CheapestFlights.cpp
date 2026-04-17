#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist;
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                if (dist[u] != 1e9 && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main() {
    Solution sol;
    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout << "Output: " << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}
