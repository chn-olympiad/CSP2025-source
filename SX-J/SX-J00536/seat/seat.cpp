#include <bits/stdc++.h>
using namespace std;
long long n, m, a[10005], w;

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	w = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	long long h = 1, l = 1;
	bool q = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == w) {
			cout << l << " " << h;
			return 0;
		}
		if (q == 0)
			h--;
		else if (q == 1)
			h++;
		if (l % 2 == 1 && h > n) {
			l++;
			h = n;
			q = 0;
		}
		if (l % 2 == 0 && h < 1) {
			l++;
			h = 1;
			q = 1;
		}
	}
	return 0;
}
