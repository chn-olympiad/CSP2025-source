#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 100, M = 1e6 + 100;
struct ed{int u,v,w;}e[M],te[N],ee[15][N];int ce,ct;
int n, m, k, f[N], rk[N], ans = 1e18;
int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
void merge(int a, int b, int t)
{
	if(t) a = find(a), b = find(b);
	if(a==b) return;
	if(rk[a]<rk[b]) swap(a,b);
	rk[a] = max(rk[a],rk[b]+1), f[b] = a;
}
int make()
{
	int i, ans = 0;
	for(i=1;i<=n+k;i++) f[i] = i, rk[i] = 1;
	ct = 0;
	for(i=1;i<=ce;i++)
	{
		int u = find(e[i].u), v = find(e[i].v);
		if(u!=v) ans += e[i].w, merge(u,v,0), te[++ct] = e[i];
	}
	return ans;
}

ed s[15][N];int cnt[15], pri[15];
void dfs(int dep, int now)
{
	if(dep==k) return;
	int p1 = 1, p2 = 1, i;
	cnt[dep+1] = cnt[dep];
	for(i=1;i<=cnt[dep];i++) s[dep+1][i] = s[dep][i];
	dfs(dep+1,now);
	ce = 0;
	while(p1<=cnt[dep]||p2<=n)
	{
		if(p1<=cnt[dep]&&(p2>n||s[dep][p1].w<=ee[dep][p2].w)) e[++ce] = s[dep][p1++];
		else e[++ce] = ee[dep][p2++];
	}
	ans = min(ans,make()+now+pri[dep]);
	for(i=1;i<=ct;i++) s[dep+1][i] = te[i];
	cnt[dep+1] = ct;
	dfs(dep+1,now+pri[dep]);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i, j;
	scanf("%lld%lld%lld", &n, &m, &k);
	for(i=1;i<=m;i++) scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	sort(&e[1],&e[m]+1,[](ed a,ed b){return a.w<b.w;}), ce = m;
	ans = make();
	for(i=0;i<k;i++)
	{
		scanf("%lld", &pri[i]);
		for(j=1;j<=n;j++) scanf("%lld", &ee[i][j].w), ee[i][j].u = n + i + 1, ee[i][j].v = j;
		sort(&ee[i][1],&ee[i][n]+1,[](ed a,ed b){return a.w<b.w;});
	}
	for(i=1;i<=ct;i++) s[0][i] = te[i];
	cnt[0] = ct;
	dfs(0,0);
	printf("%lld\n", ans);
	return 0;
}