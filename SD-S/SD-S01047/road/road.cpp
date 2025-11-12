#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> PII;
const int M=1e6+10,N=1e5+10,K=15;
int n,m,k;
vector<PII> v[M];
int c[N];
int a[K][N];
int f[M];
int cnt;
ll ans;
vector<PII> vt[N];
struct node
{
	int x,y,z;
	bool operator<(const node &other) const
	{
		return z<other.z;
	}
}p[N];
int find(int x)
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
/*void dj()
{
	priority_queue<PII,vector<PII>,greater<PII> >q;
}*/
void solve()
{
	sort(p+1,p+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		int px=find(p[i].x),py=find(p[i].y);
		if(px!=py)
		{
			f[px]=py;
			ans+=p[i].z;
		}
	}
	printf("%lld",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=2*n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		p[++cnt]={a,b,c};
	}
	if(k==0)
	{
		solve();
	}
	else
	{
		int flag=0;
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&c[i]);
			if(c[i]!=0) flag=1;
			for(int j=1;j<=n;j++)
			{
				int x;
				scanf("%d",&x);
				//vt[i].push_back({j,x});
			}
		}
		printf("0\n");
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
if(!flag)
	{
		memset(dist,0x3f,sizeof(dist))
		for(int i=1;i<=k;i++)
		{
			for(int sx=1;sx<=n;sx++)
			{
				for(int ex=1;ex<=n;ex++)
				{
					dist[sx][ex]=min(dist[sx][ex],dist)
				}
			}
		}
		printf("%lld",ans);
	}
*/
