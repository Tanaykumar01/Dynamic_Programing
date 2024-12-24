#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int ninjaTraining(int idx, vector<vector<int> > &points, int prev)
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
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != prev)
        {
            int point = points[idx][i] + ninjaTraining(idx - 1, points, i);
            maxi = max(maxi, point);
        }
    }
    return maxi;
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

    int ans = ninjaTraining(n - 1, training, -1);

    cout << "Maximum points that can be earned are : " << ans << endl;
    return 0;
}