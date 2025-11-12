#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef pair<int,pair<int,int> > ed;
typedef long long ll;
int n,m,k;
priority_queue<ed,vector<ed>,greater<ed> > pqq;
priority_queue<ed,vector<ed>,greater<ed> > pq;
int pa[10005];
int c[15];
int cc[15][10005];
int find(int x)
{
	if(pa[x]==x)
	{
		return pa[x];
	}
	return pa[x]=find(pa[x]);
}
void merge(int a,int b)
{
	int p1=find(a),p2=find(b);
	pa[p2]=p1;
}
ll lu(int nn,int c0)
{
	int cnt=0;
	ll ans=c0;
	while(cnt<nn-1)
	{
		int u=pq.top().second.first;
		int v=pq.top().second.second;
		int w=pq.top().first;
		pq.pop();
		int p1=find(u),p2=find(v);
		if(p1!=p2)
		{
			merge(p1,p2);
			ans+=w;
			cnt++;
		}
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		pqq.push({w,{u,v}});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cc[i][j]);
		}
	}
	ll ans=LLONG_MAX;
	int pos=0;
	int xx=pow(2,k);
	while(pos<xx)
	{
	  	ll c0=0;
		pq=pqq;
		int ct=0;
		for(int i=1;i<=k;i++)
		{
		    if((pos>>(k-i))&1)
		    {
			    ct++;
			    c0+=c[i];
		    	for(int j=1;j<=n;j++)
		    	{
		    		pq.push({cc[i][j],{j,ct+n}});
				}
			}
		}
	    for(int i=1;i<=n+ct;i++)
	    {
	    	pa[i]=i;
    	}
		ll res=lu(ct+n,c0);
		ans=min(res,ans);
		pos++;
	}
	cout<<ans;
	return 0;
}