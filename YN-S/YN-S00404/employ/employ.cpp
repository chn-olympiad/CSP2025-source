#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 18;
ll n, m, a[N], vis[N], p[N], ans;
string s;

void dfs(int x) {
	if (x == n + 1) {
		int cnt = 0, tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (tmp >= a[p[i]] || s[i] == '0') {
				tmp++;
			} else {
				cnt++;
			}
		}
		ans += (cnt >= m);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			p[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}