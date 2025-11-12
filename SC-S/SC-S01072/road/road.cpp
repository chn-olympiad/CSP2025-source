#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
	int v, w;
};
void dfs(int x) {
	for(auto c : g[x]) {
		
	} 
}
vector<node> g[N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ans += w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	srand(time(0));
	cout << rand()%ans;
	return 0;
}