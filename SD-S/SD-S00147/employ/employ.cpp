#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 510;
int n, m, c[N], a[N];
long long ans, num;
char s[N];
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
		do {
			num = 0;
			for (int i = 1; i <= n; i++) {
				if (num >= c[a[i]] || s[i] == '0') {
					num++;
				}
			}
			if (n - num >= m) {
				ans = (ans + 1) % mod;
			}
		} while (next_permutation(a + 1, a + n + 1));
		printf("%lld", ans);
		return 0;
	}
	if (n == m) {
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0' || c[i] == 0) {
				printf("0");
				return 0;
			}
		}
	}
	ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = (ans * i) % mod;
	}
	printf("%lld", ans);
	return 0;
}
