#include<bits/stdc++.h>
using namespace std;
int f[1050],n,m,k;
long long sum=999999999999,cnt=0;
struct st
{
	int c,a[1010];
};
struct mp
{
	int u,v,w;
};
//vector<int> tree1[1010];
//vector<int> edge1[1010];
//vector<int> tree2[1010];
//vector<int> edge2[1010];
st e[20];
mp r[1001000],h[1001000];
int s[300010];
int find1(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	else
	{
		return f[x]=find1(f[x]);
	}
}
bool cmp(mp x,mp y)
{
	return x.w<y.w;
}
int o=0;
void kruskal()
{
	for(int i=1;i<=n+20;i++)
	{
		f[i]=i;
//		tree1[i].push_back(0);
//		edge1[i].push_back(0);
	}
	o=0;
	for(int i=1;i<=m;i++)
	{
		h[i].u=r[i].u;
		h[i].v=r[i].v;
		h[i].w=r[i].w;
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find1(r[i].u)!=find1(r[i].v))
		{
			if(cnt>sum)
			{
				return;
			}
//			cout<<r[i].u<<" "<<r[i].v<<endl;
//			cout<<f[r[i].u]<<" "<<f[r[i].v]<<endl;
			cnt+=r[i].w;
			f[find1(r[i].v)]=f[r[i].u];
			s[++o]=i;
//			edge1[r[i].u][0]++;
//			edge1[r[i].v][0]++;
//			tree1[r[i].u][0]++;
//			tree1[r[i].v][0]++;
//			edge1[r[i].v].push_back(r[i].w);
//			edge1[r[i].u].push_back(r[i].w);
//			tree1[r[i].v].push_back(r[i].u);
//			tree1[r[i].u].push_back(r[i].v);
		}
	}
}
int g[20]={0},vis[1010];
//void dfs(int x,int fa,int dep)
//{
//	for(int i=1;i<=tree1[x][0];i++)
//	{
//		int v=tree1[x][i];
//		int w=edge1[x][i];
//		if(v!=fa)
//		{
//			dfs(v,x,dep+w);
//		}
//	}
//}
void make()
{
	cnt=0;
	for(int i=1;i<=k;i++)
	{
		if(g[i]==1)
		{
			cnt+=e[i].c;
			for(int j=1;j<=n;j++)
			{
				r[++m].u=n+i;
				r[m].v=j;
				r[m].w=e[i].a[j];
			}
		}
	}
	kruskal();
	for(int i=1;i<=m;i++)
	{
		r[i].u=h[i].u;
		r[i].v=h[i].v;
		r[i].w=h[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		if(g[i]==1)
		{
			for(int j=1;j<=n;j++)
			{
				r[m].u=0;
				r[m].v=0;
				r[m].w=0;
				m--;
			}
		}
	}
//	cout<<cnt<<endl;
	sum=min(sum,cnt);
}
void dfs1(int x)
{
	if(x==k)
	{
		make();
		return;
	}
	g[x+1]=1;
	dfs1(x+1);
	g[x+1]=0;
	dfs1(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>e[i].c;
		for(int j=1;j<=n;j++)
		{
			cin>>e[i].a[j];
		}
	}
	kruskal();
	sum=cnt;
	for(int i=1;i<=o;i++)
	{
		r[i].u=r[s[i]].u;
		r[i].v=r[s[i]].v;
		r[i].w=r[s[i]].w;
	}
	for(int i=o+1;i<=m;i++)
	{
		r[i].u=0;
		r[i].v=0;
		r[i].w=0;
	}
	m=o;
	o=0;
	dfs1(0);
//	make();
	cout<<sum;
	return 0;
}

