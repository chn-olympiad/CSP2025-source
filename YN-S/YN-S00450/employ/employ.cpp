#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4 + 10;
ll n, m, ans, naixin[N];
bool flag[N];
string s;

void dfs(ll dep, ll cnt) {
	if (dep == n) {
		if (cnt >= m) {
			ans++;
		}
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (flag[i])
			continue;
		if (cnt >= naixin[i] || s[dep] == '0') {
			flag[i] = true;
			dfs(dep + 1, cnt);
			flag[i] = false;
		} else {
			flag[i] = true;
			dfs(dep + 1, cnt + 1);
			flag[i] = false;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> naixin[i];
	}
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}