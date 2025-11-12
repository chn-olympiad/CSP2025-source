#include <bits/stdc++.h>
using namespace std;
int a[110];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, k, l, h;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	k = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == k) {
			l = (i + n - 1) / n;
			if (l % 2 == 1) {
				h = i % n;
				if (i % n == 0)
					h = n;
			} else
				h = n - i % n + 1;
		}
	}
	cout << l << " " << h;
	return 0;
}
