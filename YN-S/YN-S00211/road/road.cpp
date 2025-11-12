#include <bits/stdC++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k;

struct node {
	int u, w;
	friend bool operator<(node a, node b) {
		return a.w > b.w;
	}
};
vector<node>e[N];

//void dij() {
//	priority_queue<node>q;
//	q.push({s, 0})
//	dis[s] = 0, vis[s] = 0;
//	for (; !q.empty();) {
//		node now = q.top();
//		q.pop();
//		for (auto i : e[now.u]) {
//			if (dis[now.u] > dis[i.u]) {
//				dis[now.u] = dis[i.u];
//			}
//		}
//	}
//}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int sum = 0, Min = 1e9;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		Min = min(Min, w);
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	cout << Min;
	return 0;
}