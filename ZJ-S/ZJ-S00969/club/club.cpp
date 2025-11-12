#include <bits/stdc++.h>

#define int long long

using namespace std;

int read() {
	int x = 0, y = 1; char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') y = -1;
		c = getchar();
	}
	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
	return x * y;
}

const int N = 1e5 + 10;

int a[N][3], n, ans;
vector<int> g[3];

void solve() {
	n = read();
	ans = 0; g[0].clear(), g[1].clear(), g[2].clear();
	for (int i = 1; i <= n; ++i) {
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
		int mx = -1, id = -1;
		if(mx < a[i][0]) mx = a[i][0], id = 0;
		if(mx < a[i][1]) mx = a[i][1], id = 1;
		if(mx < a[i][2]) mx = a[i][2], id = 2;
		ans += mx;
		g[id].push_back(i); 
	}
	int flag = -1;
	for (int i = 0; i <= 2; ++i)
		if(g[i].size() > n / 2) {
			flag = i; break;
		}
	if(flag == -1) cout << ans << '\n';
	else {
		for (int i = 0; i < g[flag].size(); ++i) {
			int pos = g[flag][i];
			g[flag][i] = a[pos][flag] - max(a[pos][(flag + 1) % 3], a[pos][(flag + 2) % 3]);	
		}
		sort(g[flag].begin(), g[flag].end());
		for (int i = 0; i < g[flag].size() - n / 2; ++i) ans -= g[flag][i];
		cout << ans << '\n';
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int __ = read(); 
	while(__--) solve();
	return 0;
}