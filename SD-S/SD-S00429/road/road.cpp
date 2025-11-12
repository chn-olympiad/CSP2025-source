#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[12],d[12][20009],fa[1000009],ans;
multiset<pair<int,pair<int,int> > >s;
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	ans=0x3f3f3f3f3f3f3f3f;
	cin>>n>>m>>k;
	int x=0,y=0,w=0;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		if(x==y)
		{
			cout<<'a';
		}
		else
		{
			s.insert({w,{x,y}});
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
		}
	}
	int sum=0,cnt=0,cho=0;
	for(int i=0;i<=(1<<k)-1;i++)
	{
	//	cout<<i<<endl;
		sum=0,cnt=0,cho=0;
		for(int j=1;j<=k;j++)
		{
			if((i>>(j-1))&1)
			{
				cho++;
				sum+=c[j];
				for(int b=1;b<=n;b++)
				{
					s.insert({d[j][b],{j+n,b}});
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			fa[j]=j;
		}
		for(pair<int,pair<int,int> > j:s)
		{
			x=find(j.second.first),y=find(j.second.second);
			if(x!=y)
			{
				fa[x]=y;
				sum+=j.first; 
				cnt++;
			}
			if(cnt>=n+cho-1)
			{
				break;
			}
		}
		for(int j=1;j<=k;j++)
		{
			if((i>>(j-1))&1)
			{
				for(int b=1;b<=n;b++)
				{
					s.erase(s.lower_bound({d[j][b],{j+n,b}}));
				}
			}
		}
	//	cout<<sum<<endl;
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}
