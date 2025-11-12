#include <bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
bool  vis[N];
ll sum[N], jlans = 1, a[N], tot;
priority_queue<pair<ll, int> >pq;

void dfs(ll n, ll tep) {
	if (tep == n) {
		ll to = -1, ans = 0;
		for (int i = 1; i <= tot; i++) {
			if (sum[i] > 0x7ff6fcf5c2a0)
				continue;
			to = max(to, sum[i]);
			ans += sum[i];

		}
		if (ans > to * 2 && ans <= 0x7ff6fcf5c2a0 ) {

			jlans = (jlans + 1) % 998244353;
		}
		return ;
	}

	for (int i = 1; i <= n; i++) {
//		cout << 1;
		if (vis[i])
			continue;
		sum[++tot] = a[i];

		vis[i] = 1;
		dfs(n, tep + 1);
		vis[i] = 0;
		tot--;
	}

}

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	cout << "Hi word\n";

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int g = 3; g <= n; g++) {
		memset(vis, 0, sizeof(vis));
		memset(sum, 0, sizeof(sum));
		tot = 0;

		dfs(g, 1);
	}
	cout << jlans % 998244353;
	return 0;
}














