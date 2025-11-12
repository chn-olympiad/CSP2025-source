#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], t, sum;

inline bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;//n––m¡–
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	t = a[1];
	stable_sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (a[n * i] <= t) {
			for (int j = 1; j <= n; j++) {
				if (a[n * (i - 1) + j] == t) {
					sum = j;
					break;
				}
			}
			if (i % 2 == 1) {
				cout << i << " " << sum;
			} else {
				cout << i << " " << n - sum + 1;
			}

			break;
		}
	}

	return 0;
}