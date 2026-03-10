#include <bits/stdc++.h>
using namespace std;


int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[0] - a[1]) > (b[0] - b[1]);  
    });
    
    int energy = 0;
    
    for(int i = tasks.size() - 1; i >= 0; i--) {
        int actual = tasks[i][0];
        int minimum = tasks[i][1];
        
    
        if(energy < minimum) {
            
            energy = minimum;
        }
        
        
        energy += actual;
    }
    
    return energy;
}

int main()
{
    
    vector<vector<int>> tasks1 = {{1,3},{2,4},{10,11},{10,12},{8,9}};
    cout << "Example 1 - Minimum Energy: " << minimumEffort(tasks1) << endl;
    
   
    vector<vector<int>> tasks2 = {{1,2},{2,4},{4,8}};
    cout << "Example 2 - Minimum Energy: " << minimumEffort(tasks2) << endl;
    
    return 0;
}