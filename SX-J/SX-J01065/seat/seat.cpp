#include <bits/stdc++.h>
using namespace std;
int a[105];

int b[15][15] = {0};

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c = 0, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < (n * m) ; i++) {
		cin >> a[i];
		cnt++;
	}
	int t = a[0];
	sort(a, a + cnt, cmp);
	for (int i = 1; i <= m; i++) {
		if (m % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				b[j][i]  = a[++c];
			}
		}
		if (m % 2 == 0) {
			for (int j = n ; j >= 1; j--) {
				b[j][i]  = a[++c];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == t) {
				cout << j << " " << i;
				break;
			}
		}
	}

	return 0;
}
