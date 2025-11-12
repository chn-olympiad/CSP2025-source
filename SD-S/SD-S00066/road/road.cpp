#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e4 + 5;
const long long INF = 1e18;
typedef pair<int, int> PII;
struct Edge {
	int y, v;
	Edge(int _y, int _v) {
		y = _y;
		v = _v;
	}
};
int n, m, k, c[15], a[15][N];
long long dist[N];
bool b[N];
vector<Edge> e[N];
priority_queue<PII, vector<PII>, greater<PII> > q;
long long dijkstra(int s, int t) {
	memset(b, false, sizeof(b));
	for (int i = 0; i <= n; i ++ ) dist[i] = INF;
	q.push(make_pair(0, s));
	dist[s] = 0;
	while (!q.empty()) {
		auto x = q.top().second;
		q.pop();
		if (b[x]) continue;
		b[x] = true;
		if (x == t) return dist[t];
		for (auto i : e[x]) {
			if (dist[x] + i.v < dist[i.y]) {
				dist[i.y] = dist[x] + i.v;
				q.push(make_pair(dist[i.y], i.y));
			}
		}
	}
	if (dist[t] >= INF) return -1;
	return dist[t];
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	while (m -- ) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		e[x].push_back(Edge(y, v));
		e[y].push_back(Edge(x, v));
	}
	for (int i = 1; i <= k; i ++ ) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j ++ ) {
			scanf("%d", &a[i][j]);
			e[i].push_back(Edge(j, a[i][j]));
			e[j].push_back(Edge(i, a[i][j]));
		}
	}
	printf("%lld\n", dijkstra(1, n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
