#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,m,k,f[N],ans,c[N],x[15][10005];
ll find(ll x,ll check)
{
	//if(check==1)cout<<f[x]<<" "<<x<<endl;
	if(f[x]==x)return x;
	return f[x]=find(f[x],check);
}
struct node
{
	ll u,v,w;
}a[N];
bool cmp(node n,node m)
{
	return n.w<m.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&x[i][j]);
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(a[i].u>a[i].v)swap(a[i].u,a[i].v);
		/*if(i==3)
		{
			find(a[i].u,1);
			cout<<a[i].u<<" "<<a[i].v<<endl;
		}*/
		ll fx=find(a[i].u,0);
		ll fy=find(a[i].v,0);
		if(fx!=fy)f[fx]=f[find(fy,0)],ans+=a[i].w;
		/*for(int j=1;j<=n;j++)
		{
			cout<<f[j]<<" ";
		}puts("");*/
	}
	printf("%lld\n",ans);
}