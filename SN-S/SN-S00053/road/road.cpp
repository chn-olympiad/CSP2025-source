#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,fa[10015],uu,vv,ww,da,js;
struct bi
{
	ll u,v,w;
}a[12000015];
ll find(ll x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
bool cmp(bi x,bi y)
{
	return x.w<y.w;
}
void sol_k0()
{
	for(ll i=1;i<=n;i++) fa[i]=i;
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&uu,&vv,&ww);
		a[i].u=uu,a[i].v=vv,a[i].w=ww;
	}
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=m;i++)
	{
		//cout<<find(a[i].u)<<" "<<find(a[i].v)<<endl;
		if(find(a[i].u)!=find(a[i].v))
		{
			fa[a[i].u]=fa[a[i].v];
			da+=a[i].w;
			js++;
		}
		if(js==n-1) break;
	}
	cout<<da; 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		sol_k0();
	}
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&uu,&vv,&ww);
		a[i].u=uu,a[i].v=vv,a[i].w=ww;		
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>uu;
		for(ll j=1;j<=n;j++)
		{
			m++;
			cin>>uu;
			a[m].u=n+i,a[m].v=j,a[m].w=uu;
		}
	}
	n=n+k;
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=n;i++) fa[i]=i;
	for(ll i=1;i<=m;i++)
	{
		//cout<<find(a[i].u)<<" "<<find(a[i].v)<<endl;
		if(find(a[i].u)!=find(a[i].v))
		{
			fa[a[i].u]=fa[a[i].v];
			da+=a[i].w;
			js++;
			//cout<<a[i].u<<" "<<a[i].v<<endl;
		}
		if(js==n-1) break;
	}
	cout<<da;
	return 0;
}
