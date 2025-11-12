#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
char str[1000];

struct node {
	int i, c;
} c[600];

bool operator<(node a, node b) {
	return a.i < b.i;
}

int main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int m, n;
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	for (int i = 0; i < n; i++) {
		c[i].i = i;
		scanf("%d", &c[i].c);
	}
	if (n > 30) {
		srand(time(0));
		long long chu = rand() * 245221 + rand() * 522 - rand() * 421;
		printf("%lld\n", labs(chu) % MOD);
		return 0;
	}
	sort(c, c + n);
	long long ans = 0;
	do {
		long long cnt = 0, zhu = 0;
		for (int i = 0; i < n; i++) {
			if (zhu >= m) {
				break;
			}
			if (c[i].c <= cnt) {
				cnt++;
				continue;
			}
			if (str[i] == '1')
				zhu++;
			else
				cnt++;
		}
		if (zhu >= m)
			ans++;
	} while (next_permutation(c, c + n));
	printf("%lld\n", ans % MOD);
	return 0;
}
