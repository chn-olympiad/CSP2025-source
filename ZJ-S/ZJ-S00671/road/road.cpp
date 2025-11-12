#include <bits/stdc++.h>
using namespace std;
mt19937 Rand(time(0));
#define int long long
#define endl '\n'

const int N = 1e5 + 20;
const int M = 2e6 + 20;
const int K = 15;
const int inf = 1e16;

int n,m,k,ans;
int c[K],d[N];

struct Dsu{
	vector <int> fa,siz;
	Dsu (int sz){
		fa.resize(sz + 5,0); siz.resize(sz * 4 + 5,0);
		for (int i = 1 ; i <= sz ; i++)
			fa[i] = i,siz[i] = 1;
	}
	int find (int u){ return fa[u] = (u == fa[u] ? u : find(fa[u])); }
	void merge (int u,int v){
		int fu = find(u),fv = find(v);
		if (fu == fv) return;
		if (siz[fu] >= siz[fv]){
			siz[fu] += siz[fv];
			fa[fv] = fu;
		}else{
			siz[fv] += siz[fu];
			fa[fu] = fv;
		}
	}
};
struct edge{
	int u,v,w;
};
edge e[M];

bool cmp (edge x,edge y){
	return x.w < y.w;
}
int rd (int l,int r){ return Rand() % (r - l + 1) + l; }
void Kruskal (int mask){
	int tot = 1,sum = 0,cnt = 0;
	for (int i = 1 ; i <= k ; i++){
		if ((mask >> (i - 1)) & 1){
			d[n + i] = 1;
			sum += c[i];
			cnt++;
		}else{
			d[n + i] = 0;
		}
	}
	//for (int i = 1 ; i <= n + k ; i++) cout << d[i] << ' ';
	//cout << endl;
	Dsu b(n + k);
	for (int i = 1 ; i <= m ; i++){
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if (b.find(u) == b.find(v) || !d[u] || !d[v]) continue;
		sum += w; tot++;
		if (tot == n + cnt) break;
		b.merge(u,v);
		//for (int j = 1 ; j <= n + k ; j++)
		//	cout << b.find(j) << ' ';
		//cout << endl;
	}
	//if (sum < ans) cout << mask << endl;
	ans = min(ans,sum);
}
void solve(){
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[i] = (edge){u,v,w};
	}
	bool ff = 1;
	for (int i = 1 ; i <= k ; i++){
		cin >> c[i]; ff &= (!c[i]);
		for (int j = 1 ; j <= n ; j++){
			int w; cin >> w;
			e[++m] = (edge){n + i,j,w};
		}
	}
	ans = inf;
	sort(e + 1,e + m + 1,cmp);
	for (int i = 1 ; i <= n ; i++) d[i] = 1;
	if (ff){
		Kruskal((1ll << k) - 1);
		cout << ans << endl;
		return;
	}
	if (k > 6 && m > 300000){
		Kruskal(0);
		for (int i = 0 ; i < n ; i++) Kruskal((1 << i));
		for (int i = 1 ; i <= 40 ; i++){
			int mask = rd(0,(1 << k) - 1);
			Kruskal(mask);
		}
		cout << ans << endl;
		return;
	}
	for (int mask = 0 ; mask < (1ll << k) ; mask++){
		//cout << "mask = " << mask << endl;
		Kruskal(mask);
		//cout << "??? " << ans << endl;
	}
	cout << ans << endl;
}
signed main(){
	//freopen("road3.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}
