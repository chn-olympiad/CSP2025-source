#include<bits/stdc++.h>
using namespace std;
#define N 20000
#define M 2000000
int n,m,k;

int tot=-1;
int head[N];
int Next[M];
int ver[M];
int edge[M];
void Add(int u,int v,int w)
{
	tot++;
	Next[tot]=head[u];
	head[u]=tot;
	ver[tot]=v;
	edge[tot]=w;
}

int read()
{
	char str;
	str=getchar();
	while(str<'0'||str>'9')
	{
		str=getchar();
	}
	int s=0;
	while(str>='0'&&str<='9')
	{
		s=s*10+str-'0';
		str=getchar();
	}
	return s;
}
int Fa[N],F[N],dep[N];
void krs(int root)
{
	queue<int>Q;
	Q.push(root);
	Fa[root]=-1;
	F[root]=root;
	dep[root]=1;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
//		printf("%d\n",x);
		for(int i=head[x];~i;i=Next[i])
		{
			int y=ver[i];
			int w=edge[i];
			if(F[x]==y)
			{
				continue;
			}
			if(Fa[y]==0)
			{
				Fa[y]=w;
				F[y]=x;
//				printf("%d %d %d %d?\n",x,y,Fa[y],F[y]);
				Q.push(y);
				dep[y]=dep[x]+1;
			}
			else
			{
				if(Fa[y]>w)
				{
					Q.push(y);
//				printf("%d %d %d %d!\n",x,y,Fa[y],w);
					Fa[y]=w;
					F[y]=x;
				}
			}
		}
	}
}
bool vis[20];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		u=read();
		v=read();
		w=read();
		Add(u,v,w);
		Add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		int cw=read();
		for(int j=1;j<=n;j++)
		{
			int w=read();
			Add(i+n,j,w);
			Add(j,n+i,w);
		}
	}
	krs(1);
	long long ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d %d\n",F[i],Fa[i]);
//	}
	for(int i=2;i<=n;i++)
	{
		if(F[i]>n)
		{
			if(vis[F[i]-n]==0)
			{
				vis[F[i]-n]=1;
				ans+=Fa[F[i]-n];
			}
		}
		else
		{
			ans+=Fa[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}

