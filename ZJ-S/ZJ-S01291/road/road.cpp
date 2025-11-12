// kai bai!!!
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > e[10010];
int mi[11];
int n, m, k;
int w[10010];
int wx[10010][10010];
bool vis[10010];
int res = 0;
void bfs1() {
//	cout << "ESDF" << endl;
	priority_queue<pair<int, int> > q;
	for(int i = 0; i < e[1].size(); i++) {
//		cout << 1 << ' ' << e[1][i].first << endl;
		if(wx[1][e[1][i].first] != -1 && wx[e[1][i].first][i] < e[1][i].second) {
			q.push(make_pair(wx[1][e[1][i].first], e[1][i].first));
		} else q.push(make_pair(e[1][i].second, e[1][i].first));
	} // daijia id
	vis[1] = true;
	while(!q.empty()) {
		auto edge = q.top();
		q.pop();
//		system("cls");
		cout << edge.first << ' ' << edge.second << endl;
		if(!vis[edge.second]) {
			res += edge.first;
	//		cout << edge.first << ' ' << res << endl;
			vis[edge.second] = true;
		}
		int id = edge.second;
		int len = e[id].size();
		for(int i = 0; i < len; i++) {
			if(!vis[e[id][i].first]) {
				if(wx[id][e[id][i].first] != -1 && wx[id][e[id][i].first] < e[id][i].second) {
					q.push(make_pair(wx[id][e[id][i].first], e[id][i].first));
				} else q.push(make_pair(e[id][i].second, e[id][i].first));
			}
		}
	}
	cout << res;
	return ;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	cout << 0;
	for(int i = 0; i <= 10001; i++) {
		for(int j = 0; j <= 1001; j++) {
			wx[i][j] = INT_MAX;
		}
	}
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}
	for(int i = 0; i <= k; i++) {
		mi[i] = INT_MAX;
	}
	int res = 0;
	for(int i = 1; i <= k; i++) {
		int X;
		cin >> X;
		for(int j = 1; j <= n; j++) {
			cin >> w[j];
		}
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				if(j != k) {
					wx[j][k] = min(wx[j][k], w[j] + w[k]);
					wx[k][j] = min(wx[k][j], w[j] + w[k]);
				}
			}
		}
	}
	for(int i = 0; i <= 10001; i++) {
		for(int j = 0; j <= 1001; j++) {
			if(wx[i][j] == INT_MAX) wx[i][j] = -1;
		}
	}
	bfs1();
//	cout << res;
	return 0;
}