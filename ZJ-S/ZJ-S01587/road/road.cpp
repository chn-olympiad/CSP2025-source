#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to, cost;
};
vector<edge> e[10004];
bool b[10004];
int n, m, k, u, v, w, c[15], a[15][10005], x;
long long ans;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			if (a[i][j] == 0){
				x = j;
			}
		}
		for (int j = 1; j <= n; j++){
			if (x == j) continue;
			e[x].push_back({j, a[i][j]});
		    e[j].push_back({x, a[i][j]});
		}
	}
	int num = 1, next;
	b[1] = true;
	while (num < n){
		int l = e[1].size();
		x = 1000000000;
		for (int i = 0; i < l; i++){
			if (e[1][i].cost < x && b[e[1][i].to] == false){
				x = e[1][i].cost;
				next = e[1][i].to;
			}
		}
		b[next] = true;
		num++;
		l = e[next].size();
		for (int i = 0; i < l; i++){
			e[1].push_back(e[next][i]);
		}
		ans += x;
	}
	cout << ans;
    return 0;
}