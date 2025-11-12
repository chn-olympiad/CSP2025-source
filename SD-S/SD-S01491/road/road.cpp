#include<bits/stdc++.h>
#define N 2000010
#define M 20010
#define fo(a, b, c) for(int b = a; b <= c; b++)
#define _fo(a, b, c) for(int b = a; b >= c; b--)
#define Fo(a, b) for(auto a : b)
#define pb push_back
#define lb lower_bound
using namespace std;
#define int long long
const int INF = 1e18;
int n, m, k, fa[M], vis[N], ans = INF, c[20], md;
int a[20][M];
struct edge{
	int x, y, w, id;
}e[N];
vector<edge>vec, v, v1[40], v2[40], v3;
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void mg(int x, int y){
	fa[x] = y;
}
bool cmp(edge x, edge y){
	return x.w < y.w;
}
void init(int stat, int op){
	fo(1, i, k){
		if(stat & (1 << (i - 1))){
			int u = i;
			if(op == 2) u += md;
			fo(1, j, n){
				if(op == 1) v1[stat].pb({j, n + u, a[u][j], 0});
				if(op == 2) v2[stat].pb({j, n + u, a[u][j], 0});
			}
		}
	}
	if(op == 1) sort(v1[stat].begin(), v1[stat].end(), cmp);
	if(op == 2) sort(v2[stat].begin(), v2[stat].end(), cmp);
}
void calc(int op, int stat){
	vec.clear(), v3.clear();
	int st2 = stat >> md;
	int st1 = stat ^ (st2 << md);
	if(op == 1){
		fo(1, i, m) vec.pb(e[i]);
		sort(vec.begin(), vec.end(), cmp);
	}
	else{
		int t0 = v.size(), t1 = v1[st1].size(), t2 = v2[st2].size();
		--t0, --t1, --t2; 
		int lst = -1;
		fo(0, i, t0){
			while(lst < t1 && v1[st1][lst + 1].w <= v[i].w) ++lst, v3.pb(v1[st1][lst]);
			v3.pb(v[i]); 
		}
		int t3 = v3.size() - 1;
		lst = -1;
		fo(0, i, t3){
			while(lst < t2 && v2[st2][lst + 1].w <= v3[i].w) 
				++lst, vec.pb(v2[st2][lst]);
			vec.pb(v3[i]);
		}
	}
}
int kru(int op, int stat){
	fo(1, i, n + 10) fa[i] = i;
	int s = 0;
	calc(op, stat);
	fo(1, i, k) if(stat & (1 << (i - 1))) s += c[i];
	Fo(cur, vec){
		int fx = find(cur.x), fy = find(cur.y);
		if(fx == fy) continue;
		mg(fx, fy), s += cur.w;
		if(op) vis[cur.id] = 1;
	}
	return s;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k, md = k >> 1;
	fo(1, i, m) cin >> e[i].x >> e[i].y >> e[i].w, e[i].id = i;
	fo(1, i, k){
		cin >> c[i];
		fo(1, j, n) cin >> a[i][j];
	}
	kru(1, 0);
	fo(1, i, m) if(vis[i]) v.pb(e[i]);
	sort(v.begin(), v.end(), cmp);
	fo(0, i, (1 << md) - 1) init(i, 1);
	fo(0, i, (1 << (k - md)) - 1) init(i, 2);
	fo(0, i, (1 << k) - 1) ans = min(ans, kru(2, i));
	cout << ans << "\n";
	return 0;
}

