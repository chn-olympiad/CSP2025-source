#include<bits/stdc++.h>
#define ll long long
using namespace std;const ll N=1e5+15;
/*
ll n,m,k,head[N],cnt=1,c[15],tu,tv,tw,goal,sum,cntl,point[N];
struct node
{
	ll to;
	ll w;
	ll nxt;
}e[N];
void add(ll u,ll v,ll w);
{
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>tu>>tv>>tw;
		add(tu,tv,tw);
		add(tv,tu,tw);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>tv>>tw;
		}
	}
	while(goal!=n)
	{
		
	}
}*/
ll n,m,k,tu,tv,tw,c[15],ain[1005];vector <pair<ll,ll > > point[1050];
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>tu>>tv>>tw;
		point[tu].insert(tv,tw);
		point[tv].insert(tv,tw);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>tw
			point[i].insert(j,tw);
			point[j].insert(i,tw);
		}
	}
	ll cnt=1;
	ain[1]=1;
	while(cnt!=n)
	{
		for(int i=1;i<=cnt;i++)
		{
			for(int j=0;j<point[ain[i]].size;j++)
		}
	}
}
