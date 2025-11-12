#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+20;
long long n,m,k,c[20],vis[N],ans,t[N],cnt,en;
struct node
{
	long long v,w;
};
vector<node> a[N];
priority_queue<pair<long long,long long> > q;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(node{v,w});
		a[v].push_back(node{u,w});
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			long long x;
			cin>>x;
			a[n+i].push_back(node{j,c[i]+x});
			a[j].push_back(node{n+i,c[i]+x});
		}
	}
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		long long x=q.top().second,d=-q.top().first;
		if(!vis[x])ans+=d;
		vis[x]=1;
		if(x>n)
		{
			en++;
			t[x-n]++;
		}
		q.pop();
		if(cnt-en>=n)
		{
			long long f=0;
			for(long long i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					f=1;
					break;
				}
			}
			if(f==0)break;
		}
		for(long long i=0;i<a[x].size();i++)
		{
			long long v=a[x][i].v,w=a[x][i].w;
			if(!vis[v])
			{
				//cout<<v<<"\n";
				q.push(make_pair(-w,v));
				cnt++;
			}
		}
	}
	long long sum=0;
	for(long long i=1;i<=k;i++)
	{
		if(t[i])sum+=c[i]*(t[i]);
	}
	cout<<ans-sum;
	return 0;
}
