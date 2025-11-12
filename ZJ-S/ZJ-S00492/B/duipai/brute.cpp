#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 100, M = 1e6 + 100;
struct ed{int u,v,w;}e[M],te[N],tee[N],ee[15][N];int ce,ct;
int n, m, k, f[N], rk[N], ans = 1e18, pri[N];
int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
void merge(int a, int b, int t)
{
	if(t) a = find(a), b = find(b);
	if(a==b) return;
	if(rk[a]<rk[b]) swap(a,b);
	rk[a] = max(rk[a],rk[b]+1), f[b] = a;
}
int make(int put)
{
	sort(&e[1],&e[ce]+1,[](ed a,ed b){return a.w<b.w;});
	int i, ans = 0;
	for(i=1;i<=n+k;i++) f[i] = i, rk[i] = 1;
	ct = 0;
	for(i=1;i<=ce;i++)
	{
		int u = find(e[i].u), v = find(e[i].v);
		if(u!=v)
		{
			ans += e[i].w, merge(u,v,0), te[++ct] = e[i];
			if(put) printf("%lldd %lld %lld\n", e[i].w, e[i].u, e[i].v);
		}
	}
	return ans;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road2.out","w",stdout);
	int i, j, l;
	scanf("%lld%lld%lld", &n, &m, &k);
	for(i=1;i<=m;i++) scanf("%lld%lld%lld", &tee[i].u, &tee[i].v, &tee[i].w);
	for(i=0;i<k;i++)
	{
		scanf("%lld", &pri[i]);
		for(j=1;j<=n;j++) scanf("%lld", &ee[i][j].w), ee[i][j].u = n + i + 1, ee[i][j].v = j;
		sort(&ee[i][1],&ee[i][n]+1,[](ed a,ed b){return a.w<b.w;});
	}
	// for(i=2;i<=2;i++)
	for(i=0;i<(1<<k);i++)
	{
		ce = 0;
		for(j=1;j<=m;j++) e[++ce] = tee[j];
		int now = 0;
		for(j=0;j<k;j++) if((i>>j)&1)
		{
			now += pri[j];
			for(l=1;l<=n;l++) e[++ce] = ee[j][l];
		}
		ans = min(ans,now+make(0));
	}
	printf("%lld\n", ans);
	return 0;
}