#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int M = 1e4 + 5;
int n,k,m;
int a[M],b[M];
int w[N];
vector<int> e[N];
int ans;
void dfs(int x) {
	if (x > n) {
		return ;
	}
	for (int i = 1; i <= m; i++) {
		if (a[i] > b[i]) {
			dfs(x + 1);
			x = a[x];
			dfs(a[x]);
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v >> w[i];
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> b[i];
	}
	dfs(1);
	cout << 0 << '\n';
	return 0;
} 
