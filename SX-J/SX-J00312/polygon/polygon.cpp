#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int n, a[N];
int ans = 0, si = 0;
int v;

bool cmp(int x, int y) {
	return x > y;
}

void check(int x) {
	for (int k = x + 1; k <= n; k++) {
		si += a[k];
		if (si > v) {
			ans++;
		}
		if (k + 1 <= n) {
			check(k);
		}
		si -= a[k];
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		v = a[i];
		for (int j = i + 1; j <= n; j++) {
			si += a[j];
			check(j);
			si -= a[j];
		}
	}
	cout << ans;
	return 0;
}
