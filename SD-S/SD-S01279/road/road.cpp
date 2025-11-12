#include<bits/stdc++.h>
using namespace std;
bool STSTST;

const int N = 1e4 + 5;
const int M = 1e6 + 5;

struct edge{
	int u,v;
	long long w;
}e[M];

int n,m,k,f[N];
long long g[(1 << 10) + 5],a[15][N],mn[N],c[15];
long long ans = LLONG_MAX;

int find(int g){return f[g] == g ? g : f[g] = find(f[g]);} 

bool EDEDED;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
//	struct _timeb TT;
//	_ftime(&TT);
//	default_random_engine rng(TT.millitm);
//	mt19937 rnd(TT.millitm);
	
	cin >> n >> m >> k;
	for (int i = 1;i <= n;++i) f[i] = i;
	for (int i = 1;i <= m;++i){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}sort(e + 1,e + m + 1,[](edge x,edge y){return x.w < y.w;});
	for (int i = 1;i <= k;++i){
		cin >> c[i];
		for (int j = 1;j <= n;++j) cin >> a[i][j];
	}for (int msk = 1;msk < (1 << k);++msk){
		for (int i = 1;i <= n;++i) mn[i] = LLONG_MAX;
		for (int i = 1;i <= k;++i){
			if ((1 << (i - 1)) & msk){
				g[msk] += c[i];
				for (int j = 1;j <= n;++j) mn[j] = min(mn[j],a[i][j]);
			}
		}for (int i = 1;i <= n;++i) g[msk] += mn[i];
	}int cnt = 0;
	long long sum = 0;
	for (int _ = 1;_ <= m;++_){
		if (cnt == n - 1) break;
		int fx = find(e[_].u),fy = find(e[_].v);
		if (fx == fy) continue;
		for (int msk = 1;msk < (1 << k);++msk){
			ans = min(ans,sum + g[msk]);
			long long mn1 = LLONG_MAX,mn2 = LLONG_MAX;
			for (int i = 1;i <= k;++i){
				if ((1 << (i - 1)) & msk) mn1 = min(mn1,a[i][fx]),mn2 = min(mn2,a[i][fy]);
			}g[msk] -= max(mn1,mn2);
		}for (int i = 1;i <= k;++i) a[i][fx] = min(a[i][fx],a[i][fy]);
		f[fy] = fx,cnt++,sum += e[_].w;
	}ans = min(ans,sum);
	cout << ans;
	
//	cerr << "\ntime used: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000.0 << " ms\n";
//	cerr << "memory used: " << abs(&STSTST - &EDEDED) / 1024.0 / 1024.0 << " MB\n";
	return 0;
}

