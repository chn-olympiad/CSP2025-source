#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>> r[10010];
bool pt[10010];
int c[10010];
int n,m,k;
priority_queue<pair<int,int>> q,q2;
int dij(int i)
{
	memset(pt,0,sizeof(pt));
	pt[i]=1;
	int lj=0;
	for(auto v:r[i])
	{
		if(v.second-n>0)
		{
			q2.push(v);
			continue;
		}
		q.push(v);
	}
	int js=1;
	while(!q.empty()&&js<n)
	{
		int u=q.top().second;
		int w=q.top().first;
		int u2;
		int w2;
		if(!q2.empty())
		{
			u2=q2.top().second;
			w2=q2.top().first;
		}
		else
		{
			u2=-1;
			w2=-1;
		}
		if((1e9-w)>((1e9-w2)+c[u2])&&w2!=-1)
		{
			q2.pop();
			if(pt[u2])continue;
			lj+=1e9-w2;
			pt[u2]=1;
			for(auto v:r[u2])
			{
				if(pt[v.second])continue;
				q.push(v);
			}
		}
		else
		{
			q.pop();
			if(pt[u])continue;
			lj+=1e9-w;
			pt[u]=1;
			for(auto v:r[u])
			{
				if(pt[v.second])continue;
				if(v.second-n>0)
				{
					q2.push(v);
					continue;
				}
				q.push(v);
			}
			js++;
		}
	}
	return lj;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		r[u].push_back({1e9-w,v});
		r[v].push_back({1e9-w,u});
	}
	int a[k+1][n+1];
	for(int i=1;i<=k;i++)
	{
		cin>>c[n+i];
		int min=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]<a[i][min])min=j;
		}
		a[i][min]+=c[n+i];
		for(int j=1;j<=n;j++)
		{
			r[n+i].push_back({1e9-a[i][j],j});
			r[j].push_back({1e9-a[i][j],n+i});
		}
	}
	cout<<dij(1);
	return 0;
} 