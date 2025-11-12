#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10100

struct Node {
	int ed, val; //满意度，编号
};
int c[N], sum;

vector<Node> q[N];//邻接表
bool l[N];//已联通区域
priority_queue<pair<int, int> > pq;//准备连通的点：距离，编号

void f() {
	while (!pq.empty()) {
		int x = -1, juli;
		while (x == -1 || l[x] == 1) {
			x = pq.top().second;
			juli = -pq.top().first;
			pq.pop();
			if (pq.empty())
				return;
		}
		//cout << x << " " << juli << endl;
		sum += juli;
		l[x] = 1;
		for (int i = 0; i < q[x].size(); i++) {
			int v = q[x][i].ed, w = q[x][i].val;
			//cout << x << " " << v << endl;
			if (l[v] == 0) {
				int zuixiao = w;
				for (int j = 0; j < q[v].size(); j++) {
					int ed = q[v][j].ed, val = q[v][j].val;
					//cout << v << " " << ed << " " << val << endl;
					if (l[ed] == 1 && val < zuixiao)
						zuixiao = val;
				}
				pq.push({-zuixiao, v});
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, u, v, w;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		q[u].push_back({v, w});
		q[v].push_back({u, w});
	}
	int x;
	for (int i = 1; i <= k; i++) {
		cin >> x;
		for (int j = 1; j <= n; j++) {
			cin >> c[j];
			if (c[j] == 0)
				u = j;
		}
		for (int j = 1; j <= n; j++) {
			q[u].push_back({x, c[i]});
			q[x].push_back({u, c[i]});
		}

	};
	l[1] = 1;
	for (int i = 0; i < q[1].size(); i++) {
		pq.push({-q[1][i].val, q[1][i].ed});
	}
	f();
	cout << sum;
	return 0;
}