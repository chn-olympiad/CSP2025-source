#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int INT_INF = 0x3f3f3f3f;
long long LL_INF = 0x3f3f3f3f3f3f3f3f;
// ---------------------------

// ---------------------------
int ans, a[N], b[N], c[N];
// ---------------------------
void dfs(int u, int sum, int cnt1, int cnt2, int cnt3, int n) {
	if (u > n) {
		ans = max(ans, sum);
		return;
	}
	
	if (cnt1 < n / 2) dfs(u + 1, sum + a[u], cnt1 + 1, cnt2, cnt3, n);
	if (cnt2 < n / 2) dfs(u + 1, sum + b[u], cnt1, cnt2 + 1, cnt3, n);
	if (cnt3 < n / 2) dfs(u + 1, sum + c[u], cnt1, cnt2, cnt3 + 1, n);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	// ---------------------------
	int n;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
		ans = 0;
		dfs(1, 0, 0, 0, 0, n);
		cout << ans << '\n';
	}
	// ---------------------------
	
	return 0;
}
