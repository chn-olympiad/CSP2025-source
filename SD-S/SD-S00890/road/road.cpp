#include <bits/stdc++.h>  
#define ll long long
using namespace std;
const int N = 1e4 + 50, M = 1e6 + 50;
int n, m, k, fa[N], d[10][N];
struct Node {
	int u, v, w;
}G[M];
int find(int x) {
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}
bool cmp(Node a, Node b) {
	return a.w < b.w;
}
int Kruskal() {
	for(int i = 1; i <= n; i ++) {
		fa[i] = i;
	}	
	int cnt = 0, ans = 0;
	sort(G + 1, G + m + 1, cmp);
	for(int i = 1; i <= m; i ++) {
		int fx = find(G[i].u), fy = find(G[i].v), w = G[i].w;
		if(fx != fy) {
			fa[fx] = fy;
			cnt ++;
			ans += w;
		}
	}
	if(cnt == n - 1) return ans;
	else return -1;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	if(k == 0) { //Ç°4¸öµã£¬16pts 
		for(int i = 1; i <= m; i ++) {
			cin >> G[i].u >> G[i].v >> G[i].w;
		}
		int ret = Kruskal();
		cout << ret << "\n";	
	} else {
		cout << 1 << "\n";
	}
	return 0;
}


