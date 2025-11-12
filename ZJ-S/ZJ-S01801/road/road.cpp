#include<bits/stdc++.h>
using namespace std;
int n,m,k,cs;
struct E{
	int u,w,v;
}e[2000007];
struct QXX{
	int nxt,to,w;
}q[2000007];
int head[10007],cnt;
long long ans;
void add(int u,int v,int w)
{
	cnt++;
	q[cnt].to=v;
	q[cnt].w=w;
	q[cnt].nxt=head[u];
	head[u]=cnt;
}
int c[17],d[17],f[17][10007];
int t[10007];

int fa[10007],bg[10007];
int fnd(int x)
{
	if(x!=fa[x])
	{
		fa[x]=fnd(fa[x]);
		return fa[x];
	}
	return fa[x];
}
bool cmp(E x,E y)
{
	return x.w<y.w;
}
void krus()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		//bg[i]=1;
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1)
		{
			break;
		}
		int x=fnd(e[i].u),y=fnd(e[i].v);
		if(x!=y)
		{
			ans+=e[i].w;
			fa[x]=y;
			cnt++;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		//add(e[i].u,e[i].v,e[i].w);
		//add(e[i].v,e[i].u,e[i].w);
	}
	if(k==0)
	{
		sort(e+1,e+m+1,cmp);
		krus();
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			cs+=c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>f[i][j];
			}
		}
		if(cs==0)
		{
			for(int i=1;i<=k;i++)
			{
				for(int j=1;j<=n;j++)
				{
					m++;
					e[m].u=i;
					e[m].v=j;
					e[m].w=f[i][j];
				}
			}
			sort(e+1,e+m+1,cmp);
			krus();
			cout<<ans;
		}
	}
	/*for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>f[i][j];
		}
	}
	int mk=(1<<k);
	for(int x=0;x<=mk;x++)
	{
		for(int i=1;i<=k;i++)
		{
			if(((1<<(i-1)&~x))
			{
				
				for(int j=head[i];j;j=e[j].nxt)
				{
					if(e[j].w>f[e[j].to])
					{
						d[i]+=e[j].w-f[e[j].to];
					}
				}
			}
		}
		
		
	}*/
	
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
