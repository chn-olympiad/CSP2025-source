#include <iostream>
using namespace std;

const int MOD = 998244353;

int n, m, ans;
int a[20], c[20];
bool st[20];
string s;

void dfs(int u) {
	if (u > n) {
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= c[a[i]]) cnt++;
			else if (s[i] == '0') cnt++;
			else res++;
		}
		if (res >= m) ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			st[i] = 1;
			a[u] = i;
			dfs(u + 1);
			st[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
}
