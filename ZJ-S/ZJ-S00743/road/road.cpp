#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >c[10020];
int k;
bool vis1[10020];
int a[100020];
int n;
int prim()
{
	bool vis[10020]={0};
	vis[1]=1;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	int i;
	for(i=0;i<c[1].size();i++)
	{
		pair<int,int>t=c[1][i];
		if(t.second>n&&vis1[t.second-n]==0)continue;
		q.push(t);
	}
	int sum=0;
	int cnt=1;
	while(!q.empty())
	{
		int val=q.top().first;
		int nxt=q.top().second;
		q.pop();
		if(vis[nxt]==0)
		{
			vis[nxt]=1;
			for(i=0;i<c[nxt].size();i++)
			{
				pair<int,int>t=c[nxt][i];
				if(t.second>n&&vis1[t.second-n]==0)continue;
				q.push(t);
			}
			sum+=val;
			cnt++;
			if(cnt==n)return sum;
		}
	}
	return sum;
}
int minn=0x3f3f3f3f3f3f;
void dfs(int x)
{
	if(x>k)
	{
		int sum=0;
		for(int i=1;i<=k;i++)
		{
			if(vis1[i]==1)
			{
				sum+=a[i];
			}
		}
		int q=prim()+sum;
		minn=min(q,minn);
		return;
	}
	vis1[x]=1;
	dfs(x+1);
	vis1[x]=0;
	dfs(x+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		c[u].push_back({w,v});
		c[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			c[n+i].push_back({tmp,j});
			c[j].push_back({tmp,n+i});
		}
	}
	if(k==0)minn=prim();
	else dfs(1);
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
}

