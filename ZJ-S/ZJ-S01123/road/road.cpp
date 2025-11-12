#include <bits/stdc++.h>
#define fst first
#define scd second
#define db double
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector <int>
#define pii pair <int, int>
#define sz(x) ((int)x.size())
#define ms(f, x) memset(f, x, sizeof(f))
#define L(i, j, k) for (int i=(j); i<=(k); ++i)
#define R(i, j, k) for (int i=(j); i>=(k); --i)
#define ACN(i, H_u) for (int i=H[u]; i; i=E[i].nxt)
using namespace std;
char buf[1<<20], *p1=buf, *p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf, 1, 1<<20, stdin), p1==p2)?EOF:*p1++)
template <typename INT> void rd(INT &res) {
	res=0; bool f=false; char ch=getchar();
	while (ch<'0'||ch>'9') f|=ch=='-', ch=getchar();
	while (ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^48), ch=getchar();
	res=(f?-res:res);
}
template <typename INT, typename...Args>
void rd(INT &x, Args &...y) { rd(x), rd(y...); }
//dfs
const int maxn=1e4, maxm=1e6;
const int N=maxn+15, M=maxm+15;
int n, m, kn, c[N], f[N], ga[1024];
//wmr
int get_fa(int x) { return x==f[x]?x:f[x]=get_fa(f[x]); }
struct edge {
	int u, v, w;
	bool operator < (const edge &k) const { return w<k.w; }
} e[M], g[M], a[15][N];
//incra
ll kru_pre() {
	L(i, 1, n) f[i]=i;
	ll sum=0; int cnt=0;
	L(i, 1, m) {
		int u=get_fa(e[i].u), v=get_fa(e[i].v), w=e[i].w;
		if (u!=v) f[u]=v, sum+=w, e[++cnt]=e[i];
	}
	return sum;
}
ll kru() {
	L(i, 1, n+kn) f[i]=i;
	ll sum=0;
	L(i, 1, m) {
		int u=get_fa(e[i].u), v=get_fa(e[i].v), w=e[i].w;
		if (u!=v) f[u]=v, sum+=w;
	}
	return sum;
}
//lottle
signed main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	rd(n, m, kn);
	L(i, 1, m) rd(e[i].u, e[i].v, e[i].w);
	sort(e+1, e+m+1);
	ll ans=kru_pre();
	if (!kn) { printf("%lld\n", ans); return 0; }
	m=n-1;
	L(i, 1, kn) {
		rd(c[i]);
		L(j, 1, n) {
			int v; rd(v);
			a[i][j]={i+n, j, v};
		}
		sort(a[i]+1, a[i]+n+1);
	}
	ga[0]=0, ga[1]=1; int gcnt=2;
	L(i, 1, kn-1) {
		L(j, 0, gcnt-1) ga[gcnt+j]=ga[gcnt-j-1]|(1<<i);
		gcnt<<=1;
	}
	ll res=0;
	L(i, 1, gcnt-1) {
		int p=__lg(ga[i]^ga[i-1])+1;
		if (ga[i]>ga[i-1]) {
			res+=c[p];
			merge(e+1, e+m+1, a[p]+1, a[p]+n+1, g+1);
			m+=n;
			memcpy(e+1, g+1, m*sizeof(edge));
		} else {
			res-=c[p];
			int cur=1;
			L(i, 1, m) if (e[i].u!=n+p) e[cur++]=e[i];
			m-=n;
		}
		ans=min(ans, res+kru());
	}
	printf("%lld\n", ans);
	return 0;
}