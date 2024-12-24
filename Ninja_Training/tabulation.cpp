#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ninjaTraining(int n, vector<vector<int> > &points) {
    vector<vector<int> > dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]); 
    dp[0][1] = max(points[0][0], points[0][2]); 
    dp[0][2] = max(points[0][0], points[0][1]); 
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3];
}

int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<vector<int> > training(n, vector<int>(3, 0));
    cout << "Enter the training points for each day: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> training[i][j];
        }
    }

    int ans = ninjaTraining(n, training);

    cout << "Maximum points that can be earned are: " << ans << endl;
    return 0;
}