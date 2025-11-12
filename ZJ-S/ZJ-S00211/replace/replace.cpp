#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string u[N], v[N];
string s, t;
int ans;
int n, q, use[200010];
int dfs(int i) {
	int m = s.size();
	if (i == m)
		ans++;
	if (s[i] == t[i])
		dfs(i + 1);
	
	for (int j = 1; j <= n; j++) if (!use[j]) {
		int sz = u[j].size();
		if (i + sz <= m && s.substr(i, sz) == u[j] && t.substr(i, sz) == v[j]) {
			use[j] = 1;
			dfs(i + sz);
			use[j] = 0;
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> u[i] >> v[i];
	}
	for (;q--;) {
		//memset(dp, 0, sizeof(dp));
		ans = 0;
		
		cin >> s >> t;
		dfs(0);
		cout << ans << endl;
	}
}
