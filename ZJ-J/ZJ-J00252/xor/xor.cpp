#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], vis[500005];
int dfs(int now) {
	if (vis[now] != -1) return vis[now];
	int ans = 0;
	long long tmp = 0;
	for (int i = now; i <= n; i++) {
		tmp ^= a[i];
		if (tmp == k) {
			for (int j = i + 1; j <= n; j++) ans = max(ans, dfs(j));
			ans++;
			break;
		}
	}
	return vis[now] = ans;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[i] = -1;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dfs(i));
	
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
