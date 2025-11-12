#include <bits/stdc++.h>
using namespace std;
int  k, n, b[500005], ma;

void dfs(int l, int r, int ans) {

	if (l > r || r > n || l > n) {
		ma = max(ma, ans);
		return ;
	}
	int u = b[r], v = b[l - 1];
	if ((u ^ v) == k) {
		dfs(r + 1, r + 1, ans + 1);

	}

	dfs(l + 1, r, ans);
	dfs(l, r + 1, ans);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		b[i] = b[i - 1] ^ b[i];
	}
	dfs(1, 1, 0);
	cout << ma;
	return 0;
}
