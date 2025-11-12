#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define judge(S,i) ((S>>(i-1))&1)
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
const int K=11;
int n,m,s,l,k,cost[N],val[K][N],tp,siz;
ll ans=0x3f3f3f3f3f3f3f3f;
inline int read()
{
	char x=getchar();
	int ans=0;
	while(x<'0'||x>'9')
		x=getchar();
	while(x>='0'&&x<='9')
	{
		ans=(ans<<1)+(ans<<3)+(x^48);
		x=getchar();
	}
	return ans;
}
struct edge
{
	int u,v,w;
}A[M],a[N],b[K][N],c[N*K+N],d[N*K+N];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
void merge_edge(int x)
{
	int p1=1,p2=1,now=1;
	while(p1<=siz||p2<=n)
	{
		if(p1<=siz&&p2<=n)
		{
			if(cmp(c[p1],b[x][p2]))
				d[now++]=c[p1++];
			else
				d[now++]=b[x][p2++];
			continue;
		}
		if(p1<=siz)
			d[now++]=c[p1++];
		if(p2<=n)
			d[now++]=b[x][p2++];
	}
//	cout<<"QWQ"<<b[x][1].w<<endl;
	siz+=n;
	for(int i=1;i<=siz;i++)
	{
		c[i]=d[i];
//		cout<<c[i].u<<" "<<c[i].v<<" "<<c[i].w<<endl;
	}
}
struct DSU
{
	int fa[N],siz[N];
	void Clear()
	{
		for(int i=1;i<=n+k;i++)
			fa[i]=i,siz[i]=1;
	}
	int findfa(int x)
	{
		if(fa[x]==x)
			return x;
		return fa[x]=findfa(fa[x]);
	}
	bool Merge(int x,int y)
	{
		int u=findfa(x),v=findfa(y);
		if(u==v)
			return false;
		if(siz[u]<siz[v])
			swap(u,v);
		fa[v]=u;
		siz[u]+=siz[v];
		return true;
	}
}D;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		A[i].u=read();
		A[i].v=read();
		A[i].w=read();
//		cout<<i<<" "<<A[i].u<<" "<<A[i].v<<endl;
	}
//	cout<<A[m].u<<endl;
//	return 0;
	for(int i=1;i<=k;i++)
	{
		cost[i]=read();
//		cout<<cost[i]<<endl;
		for(int j=1;j<=n;j++)
		{
			val[i][j]=read();
			b[i][j]=(edge){n+i,j,val[i][j]};
		}
		sort(b[i]+1,b[i]+1+n,cmp);
	}
	sort(A+1,A+1+m,cmp);
	D.Clear();
	for(int i=1;i<=m;i++)
		if(D.Merge(A[i].u,A[i].v))
			a[++tp]=A[i];
	for(int S=0;S<(1<<k);S++)
	{
		ll sigma=0;
		siz=n-1;
		for(int i=1;i<n;i++)
			c[i]=a[i];
		for(int i=1;i<=k;i++)
			if(judge(S,i))
			{
				sigma+=cost[i];
				merge_edge(i);
			}
		D.Clear();
		for(int i=1;i<=siz;i++)
		{
			if(D.Merge(c[i].u,c[i].v))
				sigma+=c[i].w;
//			cout<<c[i].w<<endl;
		}
		if(ans>sigma)
			ans=sigma;
//		cout<<S<<" "<<sigma<<endl;
	}
	printf("%lld",ans);
}
