#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005], b[5005];
bool f[5005];
int ans, t = 1;
int MOD = 998244353;

void dfs(int k, int cnt) {
	if (cnt == k) {
		int maxn = INT_MIN, num = 0;
//		for (int i = 1; i <= k; i++) {
//			cout << b[i] << " ";
//		}
//		cout << endl;
		for (int i = 1; i <= k; i++) {
			num += b[i];
			maxn = max(maxn, b[i]);
		}
		if (num > (maxn * 2)) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == 1) {
			continue;
		}
		for (int j = i; j >= 1; j--) {
			f[j] = 1;
		}
		b[t++] = a[i];
		dfs(k, cnt + 1);
		for (int j = i; j >= 1; j--) {
			f[j] = 0;
		}
		b[--t] = 0;
	}
}

//void dfs(int k) {
//	while (next_permutation(a + 1, a + n + 1)) {
//		int maxn = INT_MIN, num = 0;
//		for (int i = 1; i <= k; i++) {
//			num += a[i];
//			maxn = max(maxn, a[i]);
//		}
//		if (num > (maxn * 2)) {
//			ans++;
//		}
//	}
//	return;
//}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 3; i <= n; i++) {
		dfs(i, 0);
		memset(b, 0, sizeof b);
		memset(f, 0, sizeof f);
		t = 1;
	}
	printf("%d", ans % MOD);
	return 0;
}
