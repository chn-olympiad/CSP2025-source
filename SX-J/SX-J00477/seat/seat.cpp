#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}
int b;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	b = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (b == a[i]) {
			b = i;
		}
	}
	if (b <= n) {
		cout << 1 << ' ' << b;
		return 0;
	} else {
		int h = b % n;
		int l = b / n + 1;
		if (l % 2 == 0) {
			cout << l << ' ' << n - h + 1;
			return 0;
		} else {
			cout << l << ' ' << h;
			return 0;
		}
	}
}
