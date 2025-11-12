#include <bits/stdc++.h>

using namespace std;

//2 2 99 100 97 98

const int N = 105;
int n, m, t;
int a[N], x[N], y[N], p[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> p[i];
	}
	t = p[1];
	sort(p+1, p+n*m+1);
	int k = 1;
	for (int i = n*m; i >= 1; i--) {
		a[k++] = p[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			y[(i-1) * n + j] = i;
		}
	}
	int cnt = 1;
	while (1) {
		for (int j = 1; j <= n; j++) {
			x[cnt] = j;cnt++;
		}
		if (cnt >= n*m) break;
		for (int j = n; j >= 1; j--) {
			x[cnt] = j;cnt++;
		}
		if (cnt >= n*m) break;
	}
	for (int i = 1; i <= n*m; i++) {
		if (t == a[i]) {
			cout << y[i] << ' ' << x[i];
			return 0;
		}
	}
//	for (int i = 1; i <= n*m; i++) {
//		cout << a[i] << ' ';printf("(%d, %d)", y[i], x[i]);
//	}
	return 0;
} 
