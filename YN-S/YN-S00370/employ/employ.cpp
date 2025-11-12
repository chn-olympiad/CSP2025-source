#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505, M = 998244353;
ll n, m, a[N], b[N], ans;
string s;
bool used[N];

void dfs(ll o) {
	if (o >= n + 1) {
		int tmp = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '1' && tmp < a[b[i]]) {
				res++;
			} else {
				tmp++;
			}
		}
		if (res >= m)
			ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (used[i] == 0) {
			b[o] = i;
			used[i] = 1;
			dfs(o + 1);
			used[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << ans % M;
	return 0;
}
