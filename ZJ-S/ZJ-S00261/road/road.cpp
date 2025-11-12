#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
	ll x,y,z;
	bool operator < (const st &u)const
	{
		return z<u.z;
	}
};
const ll N=2000010;
ll n,m,k,x,fa[N],ans;
st a[N];
ll find(ll x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			a[++m]={n+i,j,x};
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].x)!=find(a[i].y))
		{
			ans+=a[i].z;
			fa[find(a[i].y)]=find(a[i].x);
		}
	}
	cout<<ans<<"\n";
	return 0;
}