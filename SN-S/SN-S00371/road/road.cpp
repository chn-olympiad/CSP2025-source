// SN-S00371  李知颖  辅轮中学
#include <bits/stdc++.h>
#define LL long long
#define DB double
#define LB long double
#define mid ((l+r)>>1)
#define tp top()
#define pp pop()
#define si size()
#define F first
#define S second
#define modd1 998244353
#define modd2 1000000007
#define eps1 (1e-9)
#define eps2 (1e-18)
#define inf1 (2e9)
#define inf2 (1e18)

//#define modd 
//#define eps 

#define pi pair<int,int>
#define ph(x,y) push({-x,y})
#define tdis -Q.tp.F
#define tid Q.tp.S

#define maxn 1020
#define maxm 1000005
#define maxk 15


using namespace std;
/*
int add (int x,int y) { return (0LL+x+y+modd+modd)%modd; }
int mul (int x,int y) { return (1LL*x*y)%modd; }
void ADD (int &x,int y) { x=add(x,y); }
void MUL (int &x,int y) { x=mul(x,y); }
int pw (int x,LL mi) { int rt=1; for (;mi;mi>=1,MUL(x,x)) if (mi&1) MUL(rt,x); return rt; }

int sum[],inv[]; void Init ()
{
	int p=0;
	sum[1]=1; for (int i=1;i<=p;i++) sum[i]=mul(sum[i-1],i);
	inv[1]=1; for (int i=2;i<=p;i++) inv[i]=mul(inv[modd%i],modd-modd/i);
	inv[0]=1; for (int i=1;i<=p;i++) MUL(inv[i],inv[i-1]);
}
*/

struct edge { int u,v,w; } E[maxm],e[maxn*maxk];
int n,m,k; int c[maxk],a[maxk][maxn];
int b[maxn],vis[maxn],t;
int fa[maxn],siz[maxn];
LL ans,cnt;

bool cmp (edge &x,edge &y) { return x.w<y.w; }
int find (int u) { return fa[u]=(u==fa[u]?u:find(fa[u])); }
void merge (int &u,int &v,int &w)
{
	int fu=find(u),fv=find(v); if (fu==fv) return ;
	cnt+=w; if (siz[fu]<siz[fv]) swap(fu,fv);
	fa[fv]=fu,siz[fu]+=siz[fv];
}
void solve ()
{
	for (int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1; sort(e+1,e+t+1,cmp);
	int r1=0,r2=0; while (r1<m||r2<t)
	{
		if (cnt>=ans) return ; int w1=inf1,w2=inf1;
		if (r1<m) w1=E[r1+1].w; if (r2<t) w2=e[r2+1].w;
		if (w1<w2) ++r1,merge(E[r1].u,E[r1].v,E[r1].w);
		else ++r2,merge(e[r2].u,e[r2].v,e[r2].w);
	}
}
void dfs (int pos)
{
	if (pos==k+1)
	{
		t=cnt=0; for (int i=1;i<=n;i++) vis[i]=0;
		for (int i=1;i<=k;i++) if (b[i])
		{
			cnt+=c[i]; for (int j=1;j<=n;j++) e[++t]={n+i,j,a[i][j]};
		}
		solve(); ans=min(ans,cnt); return ;
	}
	if (c[pos]) b[pos]=0,dfs(pos+1); b[pos]=1,dfs(pos+1);
}
void work ()
{
	cin>>n>>m>>k; ans=inf2; for (int i=1;i<=m;i++) cin>>E[i].u>>E[i].v>>E[i].w;
	for (int i=1;i<=k;i++) { cin>>c[i]; for (int j=1;j<=n;j++) cin>>a[i][j]; }
	sort(E+1,E+m+1,cmp); dfs(1); cout<<ans;
	
	
}

int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
//	freopen (".txt","r",stdin);
//	freopen (".txt","w",stdout);
//	int T; cin>>T; while (T--)
		work(); return 0;
}
// QAQ 
//飞起来 ~ 
// road

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
