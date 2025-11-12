#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f
#define M 1001000
#define N 20000
using namespace std;

int n, m, k, head[N], cnt, u, v, w, tmp[N], c[100], ans;
bool flag[N];
struct node {
	int to, w, next;
} edge[3 * M];

void add(int u, int v, int w) {
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dijkstra(int pos) {
	memset(tmp, INF, sizeof(tmp));
	memset(flag, false, sizeof(flag));
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > st;
	tmp[pos] = 0;
	st.push({tmp[pos], pos});
	while (!st.empty()) {
		int tval = st.top().first, tind = st.top().second;
		st.pop();
		if (flag[tind]) continue;
		flag[tind] = true;
		for (int i = head[tind]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			tmp[v] = min(tmp[v], tmp[tind] + edge[i].w);
			st.push({tmp[v], v});
		}
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(head, -1, sizeof(head));
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i + 1];
		for (int j = 1; j <= n; j++) {
			cin >> tmp[j];
		}
		for (int j = 1; j <= n; j++) {
			for (int l = j + 1; l <= n; l++) {
				add(j, l, tmp[j] + tmp[l]);
				add(l, j, tmp[j] + tmp[l]);
			}
		}
	}
	memset(flag, false, sizeof(flag));
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		sort(tmp + 1, tmp + 1 + n);
		ans += tmp[2];
	}
	cout << ans << endl;
	
	return 0;
}
