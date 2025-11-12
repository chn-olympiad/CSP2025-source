#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];

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
	int t = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			t = i;
			break;
		}
	}
	cout << ceil(t * 1. / n) << " ";
	if (int(ceil(t * 1. / n)) % 2 == 0) {
		cout << n - t % n + 1;
	} else {
		if (t % n == 0)
			cout << n;
		else
			cout << t % n;
	}
	return 0;
}
