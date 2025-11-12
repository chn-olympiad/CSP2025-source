#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], b[500010], ans;

bool dfs(int sl, int ks, int sum) {
	if (b[ks] == 1) {
		return false;
	}
	if (sl == 0) {
		if (sum == k) {
			return true;
		} else {
			return false;
		}
	}
	if (dfs(sl - 1, ks + 1, sum ^ a[ks])) {
		b[ks] = 1;
		return true;
	}
	return false ;
}

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dfs(i, j, 0)) {
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
