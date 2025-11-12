#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=100005;
struct Node
{
	ll px[3];
	ll id,dx;
};
Node a[N];
ll mxid;
bool cmp(const Node &u,const Node &v)
{
	if((u.id==mxid)^(v.id==mxid))return u.id==mxid;
	if((u.id!=mxid)&&(v.id!=mxid))return u.id>v.id;
	return u.px[u.id]-u.dx<v.px[v.id]-v.dx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll T;
	cin>>T;
	while(T--)
	{
		ll n;
		cin>>n;
		ll lim=n/2;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i].px[0]>>a[i].px[1]>>a[i].px[2];
		}
		ll cnt[3]={0,0,0};
		for(ll i=1;i<=n;i++)
		{
			if(a[i].px[0]>=a[i].px[1]&&a[i].px[0]>=a[i].px[2])
			{
				a[i].id=0;
			}
			else if(a[i].px[1]>=a[i].px[0]&&a[i].px[1]>=a[i].px[2])
			{
				a[i].id=1;
			}
			else
			{
				a[i].id=2;
			}
			cnt[a[i].id]++;
		}
		if(cnt[0]<=lim&&cnt[1]<=lim&&cnt[2]<=lim)
		{
			ll ans=0;
			for(ll i=1;i<=n;i++)
			{
				ans+=max(a[i].px[0],max(a[i].px[1],a[i].px[2]));
			}
			cout<<ans<<'\n';
			continue;
		}
		mxid=cnt[0]>lim?0:cnt[1]>lim?1:2;
		for(ll i=1;i<=n;i++)
		{
			a[i].dx=max
			(
				a[i].px[(a[i].id+1)%3],
				a[i].px[(a[i].id+2)%3]
			);
		}
		sort(a+1,a+n+1,cmp);
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			if(i<=cnt[mxid]-lim)ans+=a[i].dx;
			else ans+=a[i].px[a[i].id];
		}
		cout<<ans<<'\n';
	}
	return 0;
}