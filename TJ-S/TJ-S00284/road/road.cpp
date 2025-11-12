#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

const int N=1e6+10;
const int M=1e4+10;
const db eps=1e-8;

struct node
{
	int u,v,w;
}s[N];

int c[15],a[15][M],fa[M],cho[M];

int n,m,k;
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		s[i]={x,y,z};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
}

bool cmp(node a,node b)
{
	return a.w<b.w;
}

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

ll ans;
int tot;
void solve()
{
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=find(s[i].u);
		int y=find(s[i].v);
		if(x!=y)
		{
			cho[++tot]=i;
			ans+=s[i].w;
			fa[x]=y;
		}
	}
}

void change()
{
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int cnt=c[i]+a[i][s[j].u]+a[i][s[j].v];
			if(cnt<s[j].w)s[j].w=cnt;
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	change();
	solve();
	printf("%lld",ans);
	return 0;
}
