#include <bits/stdc++.h>
using namespace std;
long long n, m, K;
long long dist[1000005], head[1000005], vi[1000005];
long long cnt;
long long aa;
long long f[10005][10005], jl[10005][10005], cl[10005];

struct node {
	int to, nxt, w;
} edge[1000006];

void add(int u, int v, int w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}
//priority_queue<pair<int, int> > q;
queue<long long> q;

void jk(int s) {
	memset(dist, 0x3f, sizeof(dist));
	memset(vi, 0, sizeof(vi));
	dist[s] = 0;
	//q.push(make_pair(0, s));
	//while (!q.empty()) {
	q.push(s);
	for (int i = 1; i < n; i++) {
		int minn = INT_MAX;
		int p = 0;
		for (int j = 1; j <= n; j++) {
			if (!vi[j] && minn > dist[j]) {
				minn = dist[j];
				p = j;
			}
		}
		vi[p] = 1;
		for (int j = head[p]; j; j = edge[j].nxt) {
			int y = edge[j].to;
			if (!vi[y] && dist[y] > dist[p] + edge[j].w) {
				dist[y] = dist[p] + edge[j].w;
				//q.push(make_pair(-dist[y], y));
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> K;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	for (int i = 1; i <= K; i++) {
		cin >> cl[0];
		for (int j = 1; j <= n; j++) {
			cin >> cl[j];
		}
		for (int k = 1; k <= n; k++) {
			for (int j = i + 1; j <= n; j++) {
				add(k, j, cl[0] + cl[k] + cl[j]);
				add(j, k, cl[0] + cl[k] + cl[j]);
			}
		}
	}
//	jk(1);
//	cout << dist[3] << endl;
	long long ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		jk(i);
		int Minn = INT_MAX;
		int cur = 0;
		for (int j = i; j <= n; j++) {
			if (j == i)
				continue;
			if (f[i][j] == 1 || f[j][i] == 1)
				continue;
			if (Minn > dist[j]) {
				Minn = dist[j];
				cur = j;
			}
		}
		f[i][cur] = 1;
		f[cur][i] = 1;
//		cout << i << " " << cur << " " << Minn << endl;
		ans += Minn;
	}
	cout << ans << endl;
	return 0;
}
