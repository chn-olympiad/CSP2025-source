#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10, M = 2e4 + 10;
struct node{ int u, v, w; };
int n, m, k, top[M], c[20], a[20][M];
int find(int x){ return top[x] == x ? x : top[x] = find(top[x]); }
void merge(int u, int v){ u = find(u); v = find(v); if(u == v)return; top[v] = u; }
bool cmp(node u, node v){ return u.w < v.w; }
node e[N], t1[N], t2[N]; int ett, tt1, tt2;
void kruskal(){
	sort(e + 1, e + ett + 1, cmp);
	for(int i = 1; i <= n; i++)top[i] = i;
	for(int i = 1; i <= ett; i++)
		if(find(e[i].u) != find(e[i].v))
			merge(e[i].u, e[i].v), t1[++tt1] = e[i];
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w, e[++ett] = {u, v, w};
	for(int i = 1; i <= k && cin >> c[i]; i++)
		for(int j = 1; j <= n; j++)cin >> a[i][j];
	kruskal(); for(int i = 1; i <= tt1; i++)t2[++tt2] = t1[i];
	ll ans = 0x7FFFFFFFFFFFFFFF; int tn = n;
	for(int i = 0; i < (1 << k); i++){
		ll sum = 0; ett = 0; n = tn; tt1 = 0;
		for(int j = 1; j <= k; j++)
			if(i & (1 << j - 1)){
				sum += c[j]; n++;
				for(int l = 1; l <= tn; l++)
					e[++ett] = {n, l, a[j][l]};
			}
		for(int j = 1; j <= tt2; j++)
			e[++ett] = t2[j];
		kruskal();
		for(int j = 1; j <= tt1; j++)
			sum += t1[j].w;
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}