#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[10010],v[10010],w[10010],c[20],a[20][10010],ans,x,mn;
vector<pair<pair<long long,long long>,long long> >h;
bool st[10010];
bool cmp(pair<pair<long long,long long>,long long>x,pair<pair<long long,long long>,long long>y)
{
	return x.second<y.second;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			h.push_back({{u[i],v[i]},w[i]});
		}
		sort(h.begin(),h.end(),cmp);
		for(int i=0;i<h.size();i++)
		{
			if((!st[h[i].first.first])||(!st[h[i].first.second]))
			{
				ans+=h[i].second;
				st[h[i].first.first]=st[h[i].first.second]=true;
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			mn=w[i];
			for(int j=1;j<=k;j++)
			{
				x=c[j]+a[j][u[i]]+a[j][v[i]];
				mn=min(mn,x);
			}
			h.push_back({{u[i],v[i]},mn});
		}
		sort(h.begin(),h.end(),cmp);
		for(int i=0;i<h.size();i++)
		{
			if((!st[h[i].first.first])||(!st[h[i].first.second]))
			{
				ans+=h[i].second;
				st[h[i].first.first]=st[h[i].first.second]=true;
			}
		}
		cout<<ans;
	}
	return 0;
}
