#include <bits/stdc++.h>
using namespace std;
int a[20][20];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m, s;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s = a[1][1];
		}
	}
	sort(a + n, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == s)
				cout << i << j;
		}
	}
	return 0;
}
