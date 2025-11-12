#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("seat.in", "r", stdin);
	fre("seat.out", "w", stdout);
	cin >> n >> m;
	int sum = n * m;
	int a[sum];
	int b[n][m];
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a, a + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b[i][j] = a[i];

		}
	}
	sort(a, a[n][m]);
	for (int i = 1; i <= n * m; i++) {
		for (int i = 1; i <= n * m; i++) {
			cout <<
		}
	}
}
