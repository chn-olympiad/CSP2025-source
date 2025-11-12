#include<bits/stdc++.h>
using namespace std;

#define pll pair<int, int>

const int maxn = 1e6 + 5;

int n, m, k;
vector<pll> a[maxn];
bool vis[maxn];

void dfs(int x, int len, int fa, int cnt) {
	if(cnt == 8){
		cout << len;
		return;
	}
	int minn = 2e9;
	int mini = 0;
	for (auto i : a[x]) {
		int a = i.first;
		int b = i.second;
		if (a == fa) continue;
		if (b < minn) {
			minn = b;
			mini = a;
		}
	}
	if (vis[mini]) dfs(mini, len + minn, x, cnt);
	else {
		cnt++;
		vis[mini] = true;
		dfs(mini, len + minn, x, cnt);
	}
}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u].push_back({u, w});
		a[u].push_back({v, w});
	}

	for (int i = 1; i <= k; i++) {
		int c, t;
		scanf("%d", &c);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &t);
			a[n + j].push_back({j, t});
			a[j].push_back({n + j, t});
		}
	}

	dfs(1, 0, 0, 0);

	return 0;
}