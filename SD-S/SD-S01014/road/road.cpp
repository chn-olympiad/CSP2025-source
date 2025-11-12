#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
const int N=1e4+50;
int fa[N],sfa[N];
int find(int i)
{
	if(fa[i]==i)return i;
	return fa[i]=find(fa[i]);
}
void merge(int i,int j)
{
	i=find(i),j=find(j);
	if(i==j)return ;
	if(sfa[i]>sfa[j])swap(i,j);
	sfa[j]+=sfa[i];
	fa[i]=j;
	return;
}
struct edge
{
	int u,v,z;
};
bool operator<(const edge& A,const edge& B){
	return A.z<B.z;
} 
ll ans=LLONG_MAX;
vector<edge>q;
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
int w[N],a[N][11];
bool vis[N];
ll kru(ll sum)
{
	ll res=sum;
	vector<edge>t;
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i,sfa[i]=1;
		if(vis[i] and i<=k)
		{
			for(int j=1;j<=n;j++)
			{
				t.push_back({i+n,j,a[j][i]});
			}
		}	
	}
	for(edge& now:q)t.push_back(now);
	sort(t.begin(),t.end());
	
	for(edge &now:t)
	{
		int u=now.u,v=now.v,z=now.z;
		if(find(u)==find(v))continue;
		merge(u,v);
//		cout<<u<<' '<<v<<' '<<z<<'\n';
		res+=z;
	}
	return res;
}
void dfs(int now,ll sum)
{
	if(now==k+1)
	{
		ans=min(ans,kru(sum));
	//	cout<<sum<<'\n';
		return;
	}
	for(int i=1;i<=k+1;i++)
	{
		if(i+now<=k+1)
		{
			vis[i+now]=1;
			dfs(i+now,sum+w[i+now]);
			vis[i+now]=0;	
		}
	}
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,z;cin>>u>>v>>z;
		q.push_back({u,v,z});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
		for(int j=1;j<=n;j++)cin>>a[j][i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

