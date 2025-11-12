#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], l = 1, f, me;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	me = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == me) {
			int ll = i % n;
			if (ll == 0)
				ll = n;
			if (f == 0)
				cout << l << " " << ll;
			if (f == 1)
				cout << l << " " << n + 1 - ll;
		}
		if (i % n == 0 && f == 1)
			f = 0, l++;
		else if (i % n == 0 && f == 0)
			f = 1, l++;
	}

	return 0;
}
