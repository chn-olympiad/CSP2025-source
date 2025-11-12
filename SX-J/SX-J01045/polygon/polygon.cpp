#include <bits/stdc++.h>
using namespace std;

long long n, a[5050], ans, p[550];
bool f = true;

void B(int n) {
	int cnt = 0;
	for (int i = 2; i < n; i++) {
		cnt += p[i];
	}
	if (cnt > p[1])
		ans++;
	return;
}

void A(int i, int j, int n) {
	if (i == n) {
		B(n);
		for (int k = 1; k <= n; k++) {
			p[k] = 0;
		}
		return;
	}
	if (j > n)
		return;
	p[i] = a[j];
	A(i + 1, j + 1, n);
	A(i, j + 1, n);
}

int main() {
	int i, j;
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] != 1)
			f = false;
	}
	sort(a + 1, a + n + 1);
	if (f) {
		for (i = 3; i <= n; i++) {
			int cnt = 1;
			for (j = 1; j <= i; j++) {
				cnt = (cnt * (n - (j - 1))) % 998244353;
			}
			for (j = i; j > 1; j++) {
				cnt /= j;
			}
			ans += cnt;
		}
		printf("%lld", ans);
		return 0;
	}
	if (n == 3) {
		if (a[1] + a[2] > a[3])
			ans = 1;
		else
			ans = 0;
		printf("%lld", ans);
		return 0;
	}
	for (i = 3; i <= n; i++) {
		A(1, 1, i);
	}
	printf("%lld", ans);
	return 0;
}
