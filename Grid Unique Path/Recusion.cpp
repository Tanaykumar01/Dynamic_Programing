#include <iostream>
using namespace std;

int solve(int m , int n){
	if(m==0 && n==0){
		return 1;
	}
	if(m < 0 || n < 0){
		return 0;
	}
	return  solve(m-1, n) + solve(m, n-1);
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