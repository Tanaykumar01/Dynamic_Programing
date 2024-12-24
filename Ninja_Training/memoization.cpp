#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int ninjaTraining(int idx, vector<vector<int> > &points, int prev, vector<vector<int> > &dp)
{
    if (idx == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != prev)
            {
                maxi = max(maxi, points[idx][i]);
            }
        }
        return maxi;
    }
    if (dp[idx][prev] != -1)
    {
        return dp[idx][prev];
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != prev)
        {
            int point = points[idx][i] + ninjaTraining(idx - 1, points, i , dp);
            maxi = max(maxi, point);
        }
    }
    return dp[idx][prev] = maxi;
}

int main()
{
    int n;
    cout << "Enter the number of days : ";
    cin >> n;

    vector<vector<int> > training(n, vector<int>(3, 0));
    cout << "Enter the training points for each day : ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> training[i][j];
        }
    }
    vector<vector<int> > dp(n + 1, vector<int>(4, -1));
    int ans = ninjaTraining(n - 1, training, 3, dp);

    cout << "Maximum points that can be earned are : " << ans << endl;
    return 0;
}