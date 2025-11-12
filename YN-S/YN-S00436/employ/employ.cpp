#include <bits/stdc++.h>
using namespace std;
const int N = 505, MOD = 998244353;
long long n, m, can, a[N], siq;
string s;
unsigned long long c, c2, c3;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d%d%d", &n, &m, &s); //nms
	for (long long i = 1; i <= n; ++i) {
		scanf("%d", a[i]);
		if (siq >= a[i]) {
			siq++;
			continue;
		} else {
			if (s[i - 1] == 1)
				can++;
			else
				siq++;
		}
	}
	for (long long i = 0; i < m; ++i) {
		c2 *= (can - i);
		c3 *= (i + 1);
	}
	c = (c2 % MOD) / (c3 % MOD);
	printf("%d", c % MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}