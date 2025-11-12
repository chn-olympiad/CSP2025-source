#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10000;
const int MAXK = 10;

int fa[MAXN + MAXK + 5];

int find(int x) {
	return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}
bool connected(int x, int y) {
	return find(x) == find(y);
}
void merge(int x, int y) {
	fa[find(x)] = find(y);
}
void init(int n) {
	for(int i = 1; i <= n; i++)
		fa[i] = i;
}

struct Edge {
	int a, b, w;
};
//vector<Edge> graph[MAXN + 5];
vector<Edge> graph, origraph;

int upgradeCost[MAXK + 5], a[MAXK + 5][MAXN + 5];

int main() {
//	freopen(R"(C:\Users\Administrator\Desktop\csps\down\road\road3.in)", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph.push_back({a, b, w});
//		graph[a].push_back({b, w});
//		graph[b].push_back({a, w});
	}
	for(int i = 1; i <= k; i++) {
		cin >> upgradeCost[i];
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if(m <= 100000 && k <= 5) {
		origraph = graph;
		long long ans = 2147483647ll * 2147483647;
		for(int t = 0; t < (1 << k); t++) {
			long long partans = 0;
			graph = origraph;
			int toUpgrade = 0;
			for(int i = 0; i < k; i++) {
				if((t >> i) & 1) {
					toUpgrade++;
					partans += upgradeCost[i + 1];
					for(int j = 1; j <= n; j++) {
						graph.push_back({n + toUpgrade, j, a[i + 1][j]});
					}
				}
			}
			sort(graph.begin(), graph.end(), [](Edge a, Edge b) {
				return a.w < b.w;
			});
			init(n + toUpgrade);
			for(int i = 0; i < graph.size(); i++) {
				if(!connected(graph[i].a, graph[i].b)) {
					merge(graph[i].a, graph[i].b);
					partans += graph[i].w;
				}
			}
			ans = min(ans, partans);
		}
		cout << ans << endl;
	} else {
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= n; j++) {
				graph.push_back({n + i, j, a[i][j]});
			}
		}
		sort(graph.begin(), graph.end(), [](Edge a, Edge b) {
			return a.w < b.w;
		});
		init(n + k);
		long long ans = 0;
		for(int i = 0; i < graph.size(); i++) {
			if(!connected(graph[i].a, graph[i].b)) {
				merge(graph[i].a, graph[i].b);
				ans += graph[i].w;
			}
		}
		cout << ans << endl;
	}
}
