#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "r", stdout);
	long long n, m;
	cin >> n >> m;
	int s[n][m];
	int a[105];
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	int x = a[1];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = a[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = a[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << i << " " << j;
		}
	}
	return 0;
}