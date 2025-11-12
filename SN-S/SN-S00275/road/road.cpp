#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define ll long long
#define PII pair<int,int>
using namespace std;

const int N=1e4+10,M=1e6+10;
const ll inf=1e18;

int n,m,k;
ll ans=inf,a[20][N],c[20];

int tt;
struct nod 
{
	int u,v,w;
	
	bool operator < (const nod &a) const
	{
		return w<a.w;
	}
	
} E[M],e[M];
bool cmp(nod a,nod b) {return a.w<b.w;}

int fa[N]; int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}

multiset<nod> se;

nod mknod(int u,int v,int w)
{
	nod a; a.u=u; a.v=v; a.w=w;
	return a;
}

void dfs(int x,int nn,ll res)
{
	if (x>k) 
	{
		for (int i=1;i<=n+k;i++) fa[i]=i;
		int num=0;
		for (auto i:se)
		{
			int u=find(i.u),v=find(i.v);
			if (u==v) continue;
			fa[u]=v; num++; res+=i.w;
			if (num==n+nn-1 || res>ans) break;
		} 
		ans=min(ans,res); 
		return;
	}
	
	dfs(x+1,nn,res); 
	multiset<nod> sse=se;
	for (int i=1;i<=n;i++) se.insert(mknod(n+x,i,a[x][i]));
	dfs(x+1,nn+1,res+c[x]); 
	se=sse;
}

int read()
{
	int x=0; char c;
	c=getchar();
	while ('0'<=c && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(); m=read(); k=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++) E[i].u=read(),E[i].v=read(),E[i].w=read();
	for (int i=1;i<=k;i++) 
	{
		c[i]=read();
		for (int j=1;j<=n;j++) a[i][j]=read();
	}
	
	sort(E+1,E+m+1,cmp);
	
	for (int i=1;i<=m;i++)
	{
		int u=find(E[i].u),v=find(E[i].v);
		if (u==v) continue; 
		fa[u]=v; se.insert(E[i]);
	}
	
	dfs(1,0,0);
	cout<<ans;
	
	return 0;
}

