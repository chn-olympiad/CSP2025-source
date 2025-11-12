#include<bits/stdc++.h>
#define ll long long
#define MAXN 10005
using namespace std;

int n,m,k;
ll d[MAXN][MAXN]={};
ll sum=0,cnt=1;
int fa[MAXN]={};

struct node{
	int u1;
	int v1;
	ll w1;
	
	bool operator < (const node &x) const{
		return x.w1<w1;
	}
};
priority_queue<node>q;

int Find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(d,0x3f3f3f3f,sizeof d);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		if(u<v) swap(u,v);
		d[u][v]=w;
	}
	for(int i=1;i<=k;i++)
	{
		ll c;
		cin>>c;
		vector<ll> o(n+1);
		for(int j=1;j<=n;j++)
		{
			cin>>o[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<j;z++)
			{
				if(j!=z)
				{
					d[j][z]=min(d[j][z],c+o[j]+o[z]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		for(int j=1;j<i;j++)
		{
			if(d[i][j]!=0x3f3f3f3f)
			{
				q.push({i,j,d[i][j]});
			}
		}
	}
	while(1)
	{
		if(cnt>=n)
			break;
		node x=q.top();
		q.pop();
		int u=x.u1;
		int v=x.v1;
		ll w=x.w1;
		int fu=Find(u);
		int fv=Find(v);
		if(fu!=fv)
		{
			sum+=w;
			fa[fu]=fv;
			cnt++;
		}
	}
	cout<<sum;
	return 0;
}