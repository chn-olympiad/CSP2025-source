#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int w;
	int u;
	int v;
};
node g[2000005];
int c[100];
int a[15][10005];
int n,m,k;
int fa[10008];
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=fa[y];
}
bool hav(int x,int y)
{
	return (find(x)==find(y));
}

bool cmp(node aaa,node aab)
{
	return (aaa.w<aab.w);
}
int zxs()
{
	int ans=0;
	sort(g+1,g+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(!(hav(g[i].u,g[i].v)))
		{
			ans+=g[i].w;
			merge(g[i].u,g[i].v);
		}
	}
	return ans;
}

signed main()
{
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=10003;i++) fa[i]=i;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		g[i].w=ww;
		g[i].u=uu;
		g[i].v=vv;
	}
	int opp=1;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) opp=0;
		int oppp=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0) 
			{
				oppp=0;
			}
		}
		if(oppp!=0) opp=0;
	}
	if(k==0)
	{
		cout<<zxs();
	}
	if(opp==1)
	{
		int cnnn=0;
		for(int i=1;i<=k;i++)
		{
			int iii;
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]==0) iii=j;
			} 
			for(int j=1;j<=n;j++)
			{
				if(iii==j) continue;
				m++;
				g[m+cnnn].u=iii;
				g[m+cnnn].v=j;
				g[m+cnnn].w=a[i][j];
			}
		}
		cout<<zxs();
	}
	return 0;
}

