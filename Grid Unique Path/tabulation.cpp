#include <iostream>
using namespace std;


int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    vector<vector<int> >dp(m,vector<int>(n,-1));
	dp[0][0] = 1;
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			int right = 0 , down = 0;
            if (i == 0 && j == 0) {
            	dp[i][j] = 1;
            } 
			else {
                if (i > 0) {
                  down = dp[i - 1][j];
                }
                if (j > 0) {
                  right = dp[i][j - 1];
                }
                dp[i][j] = down + right;
            }
        }
	}
	cout << dp[m-1][n-1] << endl;

    return 0;
}