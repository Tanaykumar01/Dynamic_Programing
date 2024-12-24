#include <iostream>
using namespace std;

vector<vector<int> >dp(16 , vector<int>(16,-1));
int solve(int m , int n){
	if(m==0 && n==0){
		return 1;
	}
	if(m < 0 || n < 0){
		return 0;
	}
	if(dp[m][n]!=-1) return dp[m][n];
	return dp[m][n] = solve(m-1, n) + solve(m, n-1);
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    cout << solve(m-1 , n-1) << endl;

    return 0;
}