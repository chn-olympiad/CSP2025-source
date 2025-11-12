#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005];
int maxn, num;

void dfs(int step) {
	if (step > n) {
		maxn = max(maxn, num);
		return;
	}
	int cnt = step;
	if (a[cnt] == k) {
		num += 1;
		dfs(step + 1);
		num -= 1;
	}
	int tot = a[cnt];
	for (int i = cnt + 1; i <= n; i++) {
		tot ^= a[i];
		if (tot == k) {
			num += 1;
			dfs(i + 1);
			num -= 1;
		}
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	int n0um = 0, n1um = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] == 1) {
			n1um++;
		}
		if (a[i] == 0) {
			n0um++;
		}
	}
	if (n1um == n && k == 0) {
		printf("%d", n / 2);
		return 0;
	}
	if (n1um + n0um == n && k == 1 && n > 10) {
		printf("%d", n1um);
		return 0;
	}
	dfs(1);
	printf("%d", maxn);
	return 0;
}
