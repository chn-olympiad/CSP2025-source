#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20;
const int INF = 0x7f7f7f7f;
typedef long long ll;
int n, m, k, c[15][N], v[15], tot = 1, dis[N], cnt[15];
bool vis[N];
bool flag;
ll ans, mans;
struct node {
	int u, w;
};

bool operator < (const node &a, const node &b) {
	return a.w > b.w;
}

node cre(int x, int y) {
	node p;
	p.u = x;
	p.w = y;
	return p;
}
priority_queue <node> pq;
vector <node> q[N];

void prim(int s) {
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	while (!pq.empty())
		pq.pop();
	vis[s] = 1;
	for (int i = 1; i <= n + k; i++)
		dis[i] = INF;
	dis[s] = 0;
	if (s >= n)
		ans += v[s - n];
	pq.push(cre(s, dis[s]));
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		int u = now.u;
		ans += now.w;
		vis[u] = 1;
		for (int i = 0; i < q[u].size(); i++) {
			int v = q[u][i].u;
			if (vis[v])
				continue;
			if (dis[v] > q[u][i].w) {
				dis[v] = q[u][i].w;
				pq.push(cre(v, dis[v]));
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		q[x].push_back(cre(y, z));
		q[y].push_back(cre(x, z));
	}
	for (int i = 1; i <= k; i++) {
		cin >> v[i];
		if (v[i])
			flag = 1;
		for (int j = 1; j <= n; j++) {
			int p;
			cin >> p;
			q[n + i].push_back(cre(j, p));
		}
	}
	if (!flag) {
		for (int i = 1; i <= k; i++) {
			q[n + k + 1].push_back(cre(n + i, 0));
		}
		for (int j = 1; j <= n; j++) {
			q[n + k + 1].push_back(cre(i, 0));
		}
		prim(n + k + 1);
		cout << ans;
		return 0;
	}
	prim(1);
	mans = ans;
	for (int i = 1; i <= k; i++) {
		ans = 0;
		prim(i + n);
		mans = min(mans, ans);
	}
	cout << mans;
}