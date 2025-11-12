#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,k,u,v,w[1005][1005],g,c[15],p,lll;
queue<long long> q;
vector<long long> e[100005];
bool vis[1005],f;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	cin>>u>>v>>g;
    	e[u].push_back(v);
    	e[v].push_back(u);
    	w[u][v]=g;
    	w[v][u]=g;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>lll;
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool ff=1;
		for(int j=1;j<=k;j++)
		{
			if(i==c[j]) ff=0;
		}
		if(ff==1)
		{
			q.push(i);
			vis[i]=1;
			break;
		}
	}
	while(!q.empty())
	{
		long long xx=q.front(),mn=1e18;
		f=0;
		q.pop();
		for(int i=0;i<e[xx].size();i++)
		{
			if(mn>w[xx][e[xx][i]]&&vis[e[xx][i]]==0)
			{
				if(e[xx][i]==c[i])
				{
					f=1;
					p=i;
					mn=0;
					break;
				}
				else if(mn>w[xx][e[xx][i]])
				{
					f=1;
					p=i;
					mn=w[xx][e[xx][i]];
				}
			}
		}
		if(f==1)
		{
			q.push(p);
			vis[p]=1;
			ans+=mn;
		}
	}
	cout<<ans;
	return 0;
}
