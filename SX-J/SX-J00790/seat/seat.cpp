#include <bits/stdc++.h>
using namespace std;
int a[105], s[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int x = n * m;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
	}
	int q = a[1], u;
	sort(a + 1, a + x + 1, greater<int>());
	for (int i = 1; i <= x; i++) {
		if (a[i] == q)
			u = i;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i % 2 == 0) && (n * (i - 1) + n + 1 - j == u)) {
				cout << i << " " << j;
				return 0;
			} else if ((i % 2 != 0) && (i == 1) && (i * j == u )) {
				cout << i << " " << j;
				return 0;
			} else if ((i % 2 != 0) && (n * (i - 1) + j == u)) {
				cout << i << " " << j;
				return 0;
			}


		}
	}





	return 0;
}
