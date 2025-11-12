#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MAXN 10005
#define MAXM 2000005
#define pii pair<int, int>
#define mod 1000000007

int n, m, k;
vector<pii > rep[MAXN];
struct ed{
	int u, v, w;
} edge[MAXM];
int cntedge = 0;
bool cmpedge (ed a, ed b) {
	return a.w < b.w;
}
int root[MAXN];
int search(int i) {
	if (root[i] == i)
		return i;
	return root[i] = search(root[i]);
}
int c[MAXN];
int a[MAXN][MAXN];
priority_queue<pii , vector<pii >, greater<pii > > heap;
bool rA = true;

int connect = 0;
int Kruskal() {
	int ans = 0;
	sort(edge + 1, edge + 1 + cntedge, cmpedge);
	for (int i = 1; i <= cntedge; ++i) {
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		cout << u << ' ' << v << ' ' << w << endl;
		if (search(u) == search(v)) 
			continue;
		++connect;
		root[search(u)] = root[search(v)];
		ans += w;
		if (connect == n - 1) {
			return ans;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		rep[u].push_back({v, w});
		rep[v].push_back({u, w});
		edge[++cntedge] = {u, v, w};
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		if (c[i] != 0)
			rA = false;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] != 0)
				rA = false;
			edge[++cntedge] = {i, j, a[i][j] + c[i]};
		}
	}
	for (int i = 1; i <= n; ++i) {
		root[i] = i;
	}
	if (rA && k) {
		cout << 0 << endl;
		return 0;
	}
	cout << Kruskal() << endl;
	return 0;
}