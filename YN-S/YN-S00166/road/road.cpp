#include <bits/stdc++.h>
using namespace std;
const int N = 10004;
int n, m, k;

struct edge {
	int from;
	int to;
	int val;
	bool choose = false;
	bool operator < (edge e2) const {
		return val < e2.val;
	}
} el[100006];
//vector<edge> g[N];
int a[11][N];
queue<int> q;
int dis[N], group[N];

int find(int x) {
	if (x != group[x])
		find(group[x]);
	return group[x];
}
bool vis[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> el[i].from >> el[i].to >> el[i].val;
		//g[u].push_back({v, w});
	}
	bool pian = true;
	for (int i = 1; i <= k; i++) {
		cin >> a[i][0];		//改造费用
		if (a[i][0] != 0)
			pian = false;
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];		//连边费用
	}
	if (pian) {		//A
		int nn = n;
		long long ans = 0;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++)
				if (a[i][j] == 0) {
					for (; nn <= 2 * n; nn++)
						el[nn] = {j, nn - n, a[i][nn - n]};
				}
		}
		for (int i = 1; i <= n; i++)
			group[i] = i;
		sort(el + 1, el + m + 1);
		for (int i = 1; i <= m; i++) {
			int x = find(el[i].from), y = find(el[i].to);
			if (x != y) {
				el[i].choose = true;
				ans += el[i].val;
				group[el[i].from] = find(el[i].to);		//并
			}
		}
		cout << ans << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		group[i] = i;
	sort(el + 1, el + m + 1);
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = find(el[i].from), y = find(el[i].to);
		if (x != y) {
			el[i].choose = true;
			ans += el[i].val;
			group[el[i].from] = find(el[i].to);		//并
		}
	}

	return 0;
}