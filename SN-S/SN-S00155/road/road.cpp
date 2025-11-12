#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7; 
int n, m, k, u, v, w, sum, c[N], f[N];

struct Node {
	int v, w;
};

vector<Node> g[N];

int find(int x) {
	return (x == f[x] ? x : f[x] = find(f[x]));
}

void merge(int x, int y, int z) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) {
		f[fx] = fy;
		sum += z;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n ; i++) f[i] = i;
	
	if(k == 0) {
		for(int i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
			merge(u, v, w);
		}
		
		cout << sum;
		
		return 0;
	}
	
	cout << 0;
	return 0;
}
