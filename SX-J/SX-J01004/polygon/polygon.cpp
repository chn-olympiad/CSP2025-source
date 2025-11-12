#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
long long n, ans;
int a[N], v[N];

void find(long long k, long long p, long long sum, long long mx) {
	if (k == 0) {
		if (sum > mx * 2) {
			ans++;
			ans = ans % 998244353;
		}
		return;
	}
	long long ymx;
	for (int i = p; i <= n; i++) {
		if (!v[i]) {
			ymx = mx;
			if (mx < a[i])
				mx = a[i];
			v[i] = 1;
			find(k - 1, i + 1, sum + a[i], mx);
			v[i] = 0;
			mx = ymx;
		}
	}
}

int jamyoung(long long x, long long y) {
	long long jee = 1, pee = 1, dk;
	for (int i = 1; i <= x; i++) {
		jee = jee * i;
	}
	for (int i = 1, j = y; i <= x; i++, j--) {
		pee = pee * j;
	}
	dk = pee / jee;
	return dk;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 50) {
		for (int k = 3; k <= n; k++) {
			memset(v, 0, sizeof(v));
			find(k, 1, 0, -1);
		}
		cout << ans;
	} else {
		for (int k = 3; k <= n; k++) {
			ans += jamyoung(k, n);
		}
		cout << ans;
	}
	return 0;
}
