#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll s[1005][1005];
ll a[1000005];
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll l=n*m;
	for(ll i=1; i<=l; i++) cin>>a[i];
	ll x=a[1];
	ll ans=0;
	sort(a+1,a+l+1,cmp);
	for(ll i=1; i<=l; i++)
	{
		if(a[i]==x) ans=i;
	}
	ll t=0;
	while(1)
	{
		if(ans-n>0) t++;
		ans-=n;
		if(ans<=n)
		{
			if(ans<1) ans+=n;
			break;
		}

	}
	t++;
	if(t%2==0) ans=n+1-ans;
	else ;

	cout<<t<<' '<<ans;
	return 0;
}
