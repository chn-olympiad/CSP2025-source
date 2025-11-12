#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pi pair<int,pair<int,int>>
int n,m,k,s,fa[10015],kfc=1,nm;
priority_queue<pi,vector<pi>,greater<pi>> q,p;
int find(int x)
{
	if(x==fa[x])
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
	cin>>n>>m>>k;
	nm=n;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		q.push({c,{a,b}});
	}
	while(kfc<n)
	{
		int c=q.top().first,a=q.top().second.first,b=q.top().second.second;
		if(find(a)!=find(b))
		{
			s+=c;
			kfc++;
			p.push({c,{a,b}});
			fa[find(a)]=fa[find(b)];
		}
		q.pop();
	}
	for(int i=1;i<=k;i++)
	{
		kfc=1;
		int mm;
		cin>>mm;
		priority_queue<pi,vector<pi>,greater<pi>> qq=p;
		for(int j=1;j<=n;j++)
		{
			int xyz;
			cin>>xyz;
			fa[j]=j;
			qq.push({xyz,{j,nm+1}});
		}
		for(int j=n+1;j<=nm+1;j++)
		{
			fa[j]=j;
		}
		int sx=0;
		while(kfc<=nm)
	{
		int c=qq.top().first,a=qq.top().second.first,b=qq.top().second.second;
		if(find(a)!=find(b))
		{
			sx+=c;
			kfc++;
			fa[find(a)]=fa[find(b)];
		}
		qq.pop();
	}
		if(sx+mm<s)
		{
			s=sx+mm;
			p=qq;
			nm++;
		}
	}
	cout<<s;
}

