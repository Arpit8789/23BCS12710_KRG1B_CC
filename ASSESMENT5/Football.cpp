#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    if (cin >> n) {
        map<string, int> score;
        string winner;
        int max_goals = 0;
        for (int i = 0; i < n; ++i) {
            string team;
            cin >> team;
            score[team]++;
            if (score[team] > max_goals) {
                max_goals = score[team];
                winner = team;
            }
        }
        cout << winner << "\n";
    }
    return 0;
}
