#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 0, n = 0;
	int arr = 0, sum = 0;
	int a[100][100];
	int b[100010];
	cin >> t;
	for (int k = 1; k <= t; k++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
	}
	for (int k = 1; k <= t; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (j == 1) {
					int arr = a[1][1];
					if (a[i][j] >= arr) {
						arr = a[i][j];
						sum = sum + arr;
					}
				}
				if (j == 2) {
					int arr = a[1][2];
					if (a[i][j] >= arr) {
						arr = a[i][j];
						sum = sum + arr;
					}
				}
				if (j == 3) {
					int arr = a[1][3];
					if (a[i][j] >= arr) {
						arr = a[i][j];
						sum = sum + arr;
					}
				}
			}
		}

	}
	cout << sum;
	return 0;
//sort(a.begin(),a.end(),greater<int>());
}
