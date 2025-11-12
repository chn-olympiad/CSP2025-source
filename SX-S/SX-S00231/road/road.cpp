#include <bits/stdc++.h>
using namespace std;
const int N = 10050;
const int M = 1000030;
int n, m, k;
long long sum;//求和dist
int ver[N];//记录城市化村庄的点权
int head[N];

struct node {
	int nxt, to, w; //记录边权
} edge[M << 1];
int cnt;

void add(int u, int v, int ww) {
	edge[++cnt].to = v;
	edge[cnt].nxt = head[u];
	edge[cnt].w = ww;
	head[u] = cnt;
}
long long d[N];
bool vis[N];
bool vv[N];

void dijkstra() {
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<long long, int> > q;
	q.push(make_pair(0, 1));
	d[1] = 0;
	while (q.size()) {

		int x = q.top().second;

		q.pop();
		if (vv[x])
			continue;
		vv[x] = true;
		//cout << x << ' ' << d[x] << endl;
		for (int i = head[x]; i; i = edge[i].nxt) {
			//cout << "**";
			int y = edge[i].to;
			int z = edge[i].w + ver[y];
			if (x > n) {
				if (vis[x]) {
					if (d[y] >  z) {
						d[y] =  z;
						q.push(make_pair(-d[y], y));
					}
				} else {
					if (d[y] >  z + d[x]) {
						d[y] =  z + d[x];
						vis[x] = true;
						q.push(make_pair(-d[y], y));
					}
				}

			} else {
				if (d[y] >  z) {
					d[y] =  z;
					q.push(make_pair(-d[y], y));
				}
			}
		}
	}
}
int s[N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	//cin.tie(0);
	//int o = 1;
	int u, v, ww;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &ww);
		//	cin >> u >> v >> ww;
		//cout << o << " ";
		//o++;
		if (u == v)
			continue;
		add(u, v, ww);
		add(v, u, ww);
	}
	//cout << k << " " << n << endl;
	int c;
	int a;

	for (int i = n + 1; i <= n + k; i++) {

		scanf("%d", &c);
		ver[i] = c;
		//cout << i << " " << n << endl;
		for (int j = 1; j <= n; j++) {
			//	cout << o << " ";
			//	o++;
			//cout << j << " ";
			scanf("%d", &a);
			add(i, j, a);
			add(j, i, a);
		}
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		//	cout << o << " ";
		//	o++;
		sum += d[i];
	}
//	int len = unique(s + 1, s + 1 + uu) - s - 1;
//	//cout << len << endl;
//	for (int i = 1; i <= len; i++) {
//		sum += d[i];
//	}
	printf("%lld", sum);
	return 0;
}