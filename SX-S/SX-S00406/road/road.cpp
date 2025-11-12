#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
long long n, m, k, a, b, c, ct[N], ans, cnt, head[N], vist[N], dist[N];
bool f[1005];
queue <long long> q;

struct node {
	long long nxt, to, w;
} edge[N * 2];

void add(long long u, long long v, long long w) {
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

void spfa(int s) {
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	vist[s] = 1;
	q.push(s);
	while (!q.empty()) {
		long long x = q.front();
		q.pop();
		vist[x] = 0;
		for (int i = head[x]; i; i = edge[i].nxt) {
			long long y = edge[i].to;
			if (dist[x] + edge[i].w + ct[x] < dist[y]) {
				dist[y] = dist[x] + ct[x] + edge[i].w;
//				cout << x << endl;
				if (!vist[y]) {
					vist[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> a >> b >> c, add(a, b, c), add(b, a, c);
	for (int i = 1; i <= k; i++) {
		cin >> ct[i + n];
		for (int j = 1; j <= n; j++)
			cin >> c, add(n + i, j, c), add(j, n + i, c);
	}
	spfa(1);
	for (int i = 1; i <= n ; i++)
		ans += dist[i];
	cout << ans;
	return 0;
}