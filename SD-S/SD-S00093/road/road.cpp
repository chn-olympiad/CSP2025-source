//没复习最小生成树 我真开心 

#include<bits/stdc++.h>
using namespace std;
int read();
void add(int u,int v,int d);
void dfs(int p);

const int N=1e4+2,M=1e6+2;
int n,m,k,cnt,res,a[15][N],h[N],fa[N];
bitset<N>f,f2;
struct edge{
	int to,dis,next;
}e[M<<2];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f2[i]=1;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(!a[i][j])
				x=j;
		}
		for(int j=1;j<=n;j++)
			if(j!=x)
			{
				add(x,j,a[i][j]);
				add(j,x,a[i][j]);
			}
	}
	f[1]=1;
	dfs(1);
	cout<<res;
	return 0;
}
int read()
{
	int val=0,sgn=1;
	char ch=getchar/*_unlocked*/();
	for(;!isdigit(ch);ch=getchar/*_unlocked*/())
		if(ch=='-')
			sgn=-1;
	for(;isdigit(ch);ch=getchar/*_unlocked*/())
		val=val*10+ch-48;
	return val*sgn;
}
void add(int u,int v,int d)
{
	e[++cnt].to=v;
	e[cnt].dis=d;
	e[cnt].next=h[u];
	h[u]=cnt;
}
void dfs(int p)
{
	if(f==f2)
		return;
	int tn=-1,mi=0x3f3f3f3f;
	for(int i=h[p];i;i=e[i].next)
		if(e[i].dis<mi&&!f[e[i].to])
		{
			tn=e[i].to;
			mi=e[i].dis;
		}
	if(tn==-1)
		dfs(fa[tn]);
	fa[tn]=p;
	f[tn]=1;
	res+=mi;
	dfs(tn);
}
