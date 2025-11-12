#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[600];
int c[6000];
int a[6000];
const long long p = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		a[i] = i;
	}
	if (n <= 10) {
		long long ans = 0;
		do {
			int sum = 0;
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] == '1') {
					if (sum >= c[a[i]]) {
						sum++;
					} else {
						cnt++;
					}
				} else if (s[i] == '0') {
					sum++;
				}
			}
			if (cnt >= m) {
				ans = ans % p + 1;
				ans %= p;
			}
		} while (next_permutation(a + 1, a + n + 1));
		printf("%lld", ans);
	} else {
		int id = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) {
				id++;
			}
		}
		n -= id;
		long long ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans * i % p;
		}
		printf("%lld", ans);
	}
	return 0;
}