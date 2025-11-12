#include <bits/stdc++.h>
using namespace std;
long long n, m, a[10005], mycj, hang, lie;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	mycj = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == mycj) {

			if (i % n != 0) {
				if ((i / n + 1) % 2 == 1)
					cout << i / n + 1 << " " << i % n;
				else
					cout << i / n + 1 << " " << n - i % n + 1;
			} else {
				if ((i / n ) % 2 == 1)
					cout << i / n << " " << n;
				else
					cout << i / n << " " << 1;

			}

		}
	}
	return 0;
}
