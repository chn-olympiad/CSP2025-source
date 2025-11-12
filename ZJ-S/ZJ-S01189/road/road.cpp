#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e2 + 10;
int n, m, t, maxx, a[30][N], fa[N], c[N];
long long ans;
struct node{
	int u, v, val;
	bool operator <(const node & x) const{
		return x.val < val;
	}
}tt;
priority_queue <node> q;
int find(int x){
	int y = x, z = x;
	while (fa[x] != x) x = fa[x];
	while (fa[y] != y) y = fa[y], fa[z] = y, z = y;
	return x;
}
void kru(){
	while (!q.empty()){
		tt = q.top();
		q.pop();
		if (find(tt.u) == find(tt.v)) continue;
		fa[find(tt.u)] = find(tt.v);
		ans += tt.val;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> t;
	for (int i = 1; i <= m; i ++){
		cin >> tt.u >> tt.v >> tt.val;
		q.push(tt);
		fa[i] = i;
	}
	for (int i = 1; i <= t; i ++){
		cin >> c[i], maxx += c[i];
		for (int k = 1; k <= n; k ++) cin >> a[i][k], maxx += a[i][k];
	}
	if (t == 0){
		kru();
		cout << ans;
	}
	else if (maxx == 0) cout << 0;
	return 0;
}