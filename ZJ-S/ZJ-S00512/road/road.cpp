#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
const int M=1e6+10;
const long long inf=1e18;
int fa[N];
struct node
{
	int u,v,w;
}t[M],e[N],g[11*N],p[11*N];
unsigned int a[11][N];
int c[N];
int len,l;
unsigned long long ans=inf;
int n,m,k;
bool cmp(node A,node B)
{
	return A.w<B.w;
}
void init()
{
	for(int i=1;i<=n+11;i++) fa[i]=i;
}
int fi(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=fi(fa[x]);
}
void merge(int x,int y)
{
	int rt1=fi(x);
	int rt2=fi(y);
	fa[rt1]=rt2;
}
unsigned long long get(int n)
{
	init();
	for(int i=1;i<=l;i++)
	{
		p[i]=g[i];
//		cout<<p[i].u<<' '<<p[i].v<<' '<<p[i].w<<'\n';
	}
	sort(p+1,p+l+1,cmp);
	long long res=0;
	int x=0;
	for(int i=1;i<=l;i++)
	{
		//cout<<p[i].u<<' '<<p[i].v<<' '<<p[i].w<<'\n';
		if(fi(p[i].u)!=fi(p[i].v))
		{
			res+=p[i].w;
			merge(p[i].u,p[i].v);
			x++;
			if(res>=ans) return ans;
			if(x==n-1) break;
		}
	}
//	cout<<res<<'\n';
	return res;
}
int main()
{
	freopen("road.in","r",stdin);//5182974424
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	sort(t+1,t+m+1,cmp);
	init();
	for(int i=1;i<=m;i++)
	{
		if(fi(t[i].u)!=fi(t[i].v))
		{
			g[++len]=t[i];
		//	g[len]=e[len];
			merge(t[i].u,t[i].v);
		}
	}
	l=len;
//	cout<<l<<'\n';
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++)
	{
		unsigned long long sum=0;
		int now=0;
		l=len;
		for(int j=i;j>0;j-=(j&-j))
		{
			
			int low=(j&-j);
			int y=log2(low)+1;
			sum+=c[y];
			if(sum>ans) break;
			now++;
			for(int v=1;v<=n;v++)
			{
				g[++l].w=a[y][v];
				g[l].u=n+now;
				g[l].v=v;
			}
		}
		if(sum<ans)ans=min(sum+get(n+now),ans);
	}
	cout<<ans;
	return 0;
}
