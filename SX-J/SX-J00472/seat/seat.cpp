#include <bits/stdc++.h>
using namespace std;
int a[105][105], b;

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	efreopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << a[i][j];
	}
	int s = n * m;
	b = a[1][1];
	sort(a + 1, a + s + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b % n == 0)
				cout << b / n << " " << n - b / m;
			else if (b % n == 1)
				cout << b / n + 1 << " " << n + b / m;
			else
				cout << b / n + 1 << " " << n - b / m;
			cout << a[i] << " ";
		}
	}
	return 0;
}