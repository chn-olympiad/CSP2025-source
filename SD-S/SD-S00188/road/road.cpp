#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e4+9,M=1e6+9,K=10;
const ll  INF=1e18+9;
struct heap{
	struct Hement{
		int w,x,g;
	}G[K+9];int top;
	inline void ins(int w,int x,int g);
	inline void dec();
	inline Hement pop();
}hs;int c[K+9];ll ans;
struct edge{
	int u,v,x;
}b[M],a[K+9][N];int f[N+K+9];
int n,m,k;

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/

inline int  read();

inline bool cmp(edge u,edge v);

inline void solve(int S);
inline int  find(int x);

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road4.in","r",stdin);
//	freopen("road4.out","w",stdout);
	
	scanf ("%d %d %d",&n,&m,&k);
	for (int i=1;i<=m;i++)
		b[i]={read(),read(),read()};
	stable_sort(b+1,b+m+1,cmp);
	for (int i=1;i<=k;i++)
	{
		c[i]=read();
		for (int j=1;j<=n;j++)
			a[i][j]={n+i,j,read()};
		stable_sort(a[i]+1,a[i]+n+1,cmp);
	}
	
	ans=INF;
	for (int i=0;i<(1<<k);i++)
	{
		if (i==954)
			i=954;
		solve(i);
	}
	
	printf ("%lld\n",ans);
	
	return 0;
}

inline int read()
{
	int o=0,c=0,g=0;
	while (c<'0' or c>'9')
		g=(c=='-'),c=getchar();
	while (c>='0' and c<='9')
		o=(o<<1)+(o<<3)+(c^48),c=getchar();
	return (!g)?o:-o;
}

inline bool cmp(edge u,edge v)
{
	return u.x<v.x;
}

inline void solve(int S)
{
	ll res=0;int tot=n,top=1;
	while (hs.top)
		hs.dec();
	
	for (int i=1;i<=k;i++)
		if (S&(1<<(i-1)))
			res+=c[i],tot++,hs.ins(i,a[i][1].x,1);
	for (int i=1;i<=n+k;i++)
		f[i]=i;
	
	int dx,dy,w,x,g;
	while (tot>1)
	{
		if ((top<=m and b[top].x<=hs.pop().x) or !hs.top)
		{
			dx=find(b[top].u),dy=find(b[top].v);
			if (dx!=dy)
				f[dx]=dy,res+=b[top].x,tot--;
			top++;
		}
		else
		{
			w=hs.pop().w,x=hs.pop().x,g=hs.pop().g,hs.dec();
			if (g<n)//还有下一个 
				hs.ins(w,a[w][g+1].x,g+1);
			
			dx=find(a[w][g].u),dy=find(a[w][g].v);
			if (dx!=dy)
				f[dx]=dy,res+=x,tot--;
		}
	}
	
	ans=min(res,ans);
}

inline int find(int x)
{
	if (f[x]==x)
		return x;
	return f[x]=find(f[x]);
}

inline void heap::ins(int w,int x,int g)
{
	G[++top]={w,x,g};
	
	int dw=top;
	while (dw/2)
	{
		if (G[dw/2].x>G[dw].x)
			swap(G[dw/2],G[dw]),dw=dw/2;
		else
			break;
	}
}

inline void heap::dec()
{
	swap(G[1],G[top]),G[top--]={0,0,0};
	
	int dw=1,rs;
	while (dw*2<=top)
	{
		rs=(dw*2+1<=top and G[dw*2].x>G[dw*2+1].x)?(dw*2+1):(dw*2);
		if (G[dw].x>G[rs].x)
			swap(G[dw],G[rs]),dw=rs;
		else
			break;
	}
}

inline heap::Hement heap::pop()
{
	return G[1];
}

