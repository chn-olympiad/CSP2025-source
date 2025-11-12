#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 505;

const ll mod = 998244353;

int n, m, c[maxn], t[maxn];

char s[maxn];

bool vis[maxn];

ll ans;

void dfs(int x) {
	if(x == n + 1) {
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(cnt >= t[i] || s[i] == '0') cnt++;
		if(n - cnt >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		t[x] = c[i];
		vis[i] = 1;
		dfs(x + 1);
		vis[i] = 0;
	}
}

void solve10() {
	dfs(1);
	cout << ans << "\n";
	return;
}

void solve1() {
	ans = 1;
	for(int i = 1; i <= n; i++) {
		ans = ans * i % mod;
		if(!c[i]) { cout << "0\n"; return; }
	}
	cout << ans << "\n";
	return;
}

void solven() {
	ans = 1;
	for(int i = 1; i <= n; i++) {
		ans = ans * i % mod;
		if(!c[i]) { cout << "0\n"; return; }
		if(s[i] == '0') { cout << "0\n"; return; }
	}
	cout << ans << "\n";
	return;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> (s + 1);
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(n <= 10) { solve10(); return 0; }
	bool flag = 1;
	for(int i = 1; i <= n; i++) if(s[i] == '0') flag = 0;
	if(flag) { solve1(); return 0; }
	if(n == m) { solven(); return 0; }
	cout << "0\n";
	return 0;
}