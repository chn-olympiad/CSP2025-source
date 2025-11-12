#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
/*====================*/
const int N=1e4+20;
const int M=1e6+10;
const int K=13;
/*====================*/
int n,m,k;
ll ans=1e18,sum1=0;
vector<pair<int,int> >e[N];
bool flag[N];
int c[N];
int a[K][N];
/*====================*/
int f[N];
int find(int x)
{
	if(f[x]!=x)
	{
		f[x]=find(f[x]);
	}
	return f[x];
}
ll solve1()
{
	priority_queue<pair<int,pair<int,int> > >q;
//	printf("%d\n",tot);
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(auto v:e[i])
		{
			if(!flag[v.first])continue;
			pair<int,int>t={v.first,i};
			q.push({0-v.second,t});
		}
	}
	ll sum=0;
	while(!q.empty())
	{
//		if(sum+sum1>=ans)return 1e18;
		auto p=q.top();
		q.pop();
		int u=p.second.first,v=p.second.second,w=p.first;
		if(find(u)==find(v))continue;
		f[find(u)]=find(v);
		sum-=w;
//		printf("debug:(%d %d %d %d)\n",tot,u,v,w);
	}
	return sum;
}
/*====================*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++)flag[i]=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			e[j].push_back({n+i,a[i][j]});
		}
	}
	for(int i=0;i<(1<<k);i++)
	{
		sum1=0;
		for(int j=0;j<k;j++)
		{
//			if(c[j+1]==0&&!(i&(1<<j)))
//			{
//				fl=1;
//				break;
//			}
			if(i&(1<<j))
			{
				flag[n+j+i]=1;
				sum1+=c[j+1];
			}
			else flag[n+j+i]=0;
		}
		if(sum1>=ans)continue;
		ans=min(ans,solve1()+sum1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
