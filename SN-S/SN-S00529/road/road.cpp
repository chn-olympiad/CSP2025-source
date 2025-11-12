#include<bits/stdc++.h>
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
#define mid(l, r) ((l + r) >> 1)
#define pii pair<int, long long>
#define sec second
#define fir first
using namespace std;
typedef long long ll;
const int N = 1e4 + 5, M = 2e6 + 5;

int n, m, k;
int fa[N], siz[N];
inline int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
inline void merge(int x, int y){
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y;
	siz[y] += siz[x];
}
struct to_city{
	ll cost;
	ll a[N];
}p[15];
struct edge{
	ll u, v, w, f;
}e[M];
inline bool cmp(edge x, edge y){
	return x.w < y.w;
}
inline ll kur(int mask){
	ll ans = 0;
//	cout << mask << ":";
	for(int i = 0; i < k; i++)
		if((mask >> i) & 1){
			ans += p[i + 1].cost;
//			cout << i + 1 << " ";
		}
//	cout << "\n";
	for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= m; i++){
		if(e[i].f != -1 && !((mask >> (e[i].f - 1)) & 1)) continue;
//		cout << e[i].f << " ";
		int u = e[i].u, v = e[i].v;
		ll w = e[i].w;
		int x = find(u), y = find(v);
		if(x != y){
			merge(x, y);
			ans += w;
			if(siz[x] == n || siz[y] == n) break;
		}
	}
//	cout << "\n";
	return ans;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w; e[i].f = -1;
	}
	for(int i = 1; i <= k; i++){
		cin >> p[i].cost;
		for(int j = 1; j <= n; j++) cin >> p[i].a[j];
	}
	int tot = m;
	for(int i = 1; i <= k; i++){
		int x = 1;
		for(int j = 2; j <= n; j++) if(p[i].a[j] < p[i].a[x]){
			x = j;
		}
		p[i].cost += p[i].a[x];
		for(int j = 1; j <= n; j++) if(x != j) e[++tot] = {x, j, p[i].a[j], i};
	}
	m = tot;
	sort(e + 1, e + m + 1, cmp);
	ll ret = 1000000000000000000ll;
	for(int i = 0; i < (1 << k); i++){
		ret = min(ret, kur(i));
//		cout << i << " : " << kur(i) << "\n";
	}
	cout << ret;
//	ret -= 5182974424;
//	cout << "\n" << ret;
	return 0;
}

