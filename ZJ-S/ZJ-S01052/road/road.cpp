//#include <bits/stdc++.h>
//using namespace std;
//int n, m, k, x, y, z, fa[10005];
//long long ans;
//struct Edge {
//	int u, v, val;
//	const bool operator< (Edge x) const {
//		return val > x.val;
//	}
//};
//priority_queue<Edge> e;
//int find(int x) {
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//int calc(void) {
//	long long ret = 0;
//	for (int i = 1; i <= n + k + k; i++)
//		fa[i] = i;
//	priority_queue<Edge> tmp = e;
//	while (!e.empty()) {
//		Edge i = e.top();
//		e.pop();
//		i.u = find(i.u);
//		i.v = find(i.v);
//		if (i.u != i.v) {
//			fa[i.u] = i.v;
//			ret += i.val;
//		}
//	}
//	e = tmp;
//	return ret;
//}
//int main(void) {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	
//	cin >> n >> m >> k;
//	for (int i = 1; i <= m; i++) {
//		cin >> x >> y >> z;
//		e.push({x, y, z});
//	}
//	
//	ans = calc();
//	for (int i = 1; i <= k; i++) {
//		priority_queue<Edge> Last = e;
//		cin >> y;
//		for (int j = 1; j <= n; j++) {
//			cin >> x;
//			e.push({n + i, j, x});
//		}
//		e.push({n + k + i, n + i, y});
//		z = calc();
//		if (z > ans)
//			e = Last;
//		else
//			ans = z;
//	}
//	
//	cout << ans;
//	return 0;
//}
//
#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, z, c[15], fa[10005];
long long ans;
struct Edge {
	int u, v, val;
};
vector<Edge> e;
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main(void) {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		e.push_back({x, y, z});
		e.push_back({x, y, z});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> x;
			e.push_back({n + i, j, x});
		}
	}
	
	sort(e.begin(), e.end(), [](Edge x, Edge y) -> bool {
		return x.val < y.val;
	});
	
	for (auto& i : e) {
		i.u = find(i.u);
		i.v = find(i.v);
		if (i.u != i.v) {
			fa[i.u] = i.v;
			ans += i.val;
		}
	}
	
	cout << ans;
	return 0;
}

