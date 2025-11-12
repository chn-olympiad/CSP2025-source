#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,k;
ll c[51][41111];
ll fa[4211111];
struct no{
	ll u,v,w;
}tr[4211111];
bool cmp(no a,no b)
{
	return a.w<b.w;
}
ll find(ll x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]); 
}
bool ch()
{
	ll op=find(1);
	for(int i=2;i<=n;i++)
	{
		if(find(i)!=op)return 0;
	}
	return 1;
}
ll ku()
{
	for(int i=1;i<=m;i++)fa[i]=i;
	sort(tr+1,tr+1+m,cmp);
	ll kkl=0;
	for(int i=1;i<=m;i++)
	{
		ll fx=find(tr[i].u),fy=find(tr[i].v);
		if(fx!=fy)
		{
			fa[fx]=fy;
			kkl+=tr[i].w;
			if(ch())break;
		}
	}
	return kkl;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>tr[i].u>>tr[i].v>>tr[i].w;
	}
	ll ooi=m;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(i==j)continue;
			tr[++ooi].w=c[i][j];
			tr[ooi].u=i+n;
			tr[ooi].v=j;
		}
	}
	m=ooi;
	cout<<ku();
	return 0;
}
