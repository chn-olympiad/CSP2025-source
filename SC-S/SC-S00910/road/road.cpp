#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> fa(n + 1);
	vector<array<int, 3>> edge(m + 1);
	for (int i = 1, u, v, w; i <= m && cin >> u >> v >> w; i++)
		edge[i] = {u, v, w};
	vector<vector<int>> A(k + 1, vector<int>(n + 1));
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			cin >> A[i][j];
	iota(fa.begin(), fa.end(), 0);
	function<int(int)> find_set = [&](int x) {
		return x == fa[x] ? x : fa[x] = find_set(fa[x]);	
	};
	auto merge = [&](int a, int b) {
		a = find_set(a), b = find_set(b);
		if (a != b) fa[a] = b;
	};
	sort(edge.begin(), edge.end(), [&](array<int, 3> &a, array<int, 3> &b){
		return a[2] < b[2];
	});
	vector<bool> flag(k + 1);
	int result = 0;
	for (int i = 1; i <= n; i++)
		if (find_set(edge[i][0]) != find_set(edge[i][1])) {
			int minn = INF, mj = -1;
			for (int j = 1; j <= k; j++) {
				int result1 = INF, result2 = INF;
				for (int u = 1; u <= n; u++) {
					if (find_set(edge[i][0]) == find_set(u))
						result1 = min(result1, A[j][u]);
					if (find_set(edge[i][1]) == find_set(u))
						result2 = min(result2, A[j][u]);
				}
				minn = min(minn, result1 + result2);
//				if (minn < result1 + result2) minn = result1 + result, mj = j;
			}
//			if (mj != -1 && !flag[mj]) minn += A[mj][0], flag[mj] = 1;
			merge(edge[i][0], edge[i][1]);
			result += min(minn, edge[i][2]);
		}
	cout << result;
	return 0;
}
