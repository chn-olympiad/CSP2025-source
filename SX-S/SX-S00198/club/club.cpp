#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010][3], b[100010];
long long sum;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i ++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j ++) {
			scanf("%d%d%d", &a[j][0], &a[j][1], &a[j][2]);
			b[j] = a[j][0];
		}
		sort(b + 1, b + 1 + n);
		for (int j = n; j > n / 2; j --) {
			sum += b[j];
		}
		printf("%lld\n", sum);
		memset(b, 0, sizeof(b));
		sum = 0;
	}
	return 0;
}
