#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=2e6+5,K=12;
#define ll long long
int n,m,k,fa[N],w[K],f[K],pt[K],st[K],top;
ll ans=1e18;
struct edge
{
	int u,v,w;
	bool operator<(const edge &b)
	{
		return w<b.w;
	}
}e[M],a[K][N];
vector<int> tmp;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	int xx=find(x),yy=find(y);
	fa[xx]=yy;
}
void kruskal()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v) continue;
		tmp.push_back(i);
		unionn(u,v);
	}
}
ll solve(int S)
{
	ll res=0;
	top=0;
	for(int i=1;i<=k;i++) if(S&f[i-1]) res+=w[i],st[++top]=i;
	for(int i=0;i<=k;i++) pt[i]=1;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int cnt=__builtin_popcount(S)+n-1;
	while(cnt>0)
	{
		int pos=0;
		for(int i=1;i<=top;i++) if(pt[st[i]]<=n&&a[st[i]][pt[st[i]]]<a[pos][pt[pos]]) pos=st[i];
		edge ee=a[pos][pt[pos]];
		pt[pos]++;
		int u=find(ee.u),v=find(ee.v);
		if(u==v) continue;
		unionn(u,v);
		res+=ee.w;
		cnt--;
		if(res>=ans) return res;
	}
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1);
	kruskal();
	for(int i=0;i<tmp.size();i++) a[0][i+1]=e[tmp[i]];
	a[0][n].w=1e9+1;
	
	f[0]=1;
	for(int i=1;i<=k;i++) f[i]=f[i-1]*2;
	for(int i=1;i<=k;i++)
	{
		w[i]=read();
		for(int j=1;j<=n;j++) a[i][j].u=i+n,a[i][j].v=j,a[i][j].w=read();
		sort(a[i]+1,a[i]+n+1);
	}
	
	for(int S=0;S<f[k];S++) ans=min(ans,solve(S));
	printf("%lld\n",ans);
	return 0;
}
