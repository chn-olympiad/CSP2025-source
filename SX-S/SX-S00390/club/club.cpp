#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int ans, n, jyh[100005];
vector<int>da;

vector<pair<int, pair<int, int>>>g(100001, {0, {0, 0}});

void dfs(int a, int b, int c, int dep, int sum) {
	if (!dep) {
		ans = max(ans, sum);
		return;
	}
	if (a < n / 2 && sum + g[dep].first > jyh[dep]) {
		jyh[dep] = sum;
		dfs(a + 1, b, c, dep - 1, sum + g[dep].first);

	}

	if (b < n / 2 && sum + g[dep].second.first > jyh[dep]) {
		jyh[dep] = sum;
		dfs(a, b + 1, c, dep - 1, sum + g[dep].second.first);
	}

	if (c < n / 2 && sum + g[dep].second.second > jyh[dep] ) {
		jyh[dep] = sum;
		dfs(a, b, c + 1, dep - 1, sum + g[dep].second.second);
	}

}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			jyh[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> c;
			g[i] = {a, {b, c}};
		}
		dfs(0, 0, 0, n, 0);
		da.push_back(ans);
	}
	for (int i = 0; i < da.size(); i++) {
		cout << da[i] << endl;
	}
	return 0;
}