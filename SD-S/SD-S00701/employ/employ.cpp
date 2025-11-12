#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505;
string pas;
int n, m;
int c[N];
ll ans;
bitset<N> vis;
int rfu, mas;

ll A(int x) {
	if (x==0 || x==1) return 1;
	return x*A(x-1);
}

void dfs(int s) {
	if (s > n) {
		if (mas >= m) ans++;
		return;
	}
	if (mas >= m) {
		ans += A(n-s+1); 
		return;
	}
	for (int i=1;i<=n;i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		if (rfu >= c[i] || pas[s] == '0') rfu++;
		else mas++;
		dfs(s+1);
		if (rfu >= c[i] || pas[s] == '0') rfu--;
		else mas--;
		vis[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> pas;
	pas = "#"+pas;
	for (int i=1;i<=n;i++) {
		cin >> c[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
