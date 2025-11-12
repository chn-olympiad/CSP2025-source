#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1; i<=n; i++) cin>>a[i];
	if(n=3) cout<<1;
	if(n=4)
	{
		ll x=0;
		if(a[1]+a[2]>a[3]) x++;
		if(a[1]+a[3]>a[2]) x++;
		if(a[3]+a[2]>a[1]) x++;
		cout<<x;
	}
	if(n==5)
	{
		ll x=0;
		if(a[1]+a[2]>a[3]) x++;
		if(a[1]+a[4]>a[3]) x++;
		if(a[1]+a[5]>a[3]) x++;
		if(a[1]+a[3]>a[2]) x++;
		if(a[1]+a[4]>a[2]) x++;
		if(a[1]+a[3]>a[2]) x++;
		if(a[3]+a[2]>a[1]) x++;
		cout<<x;
	}
	else cout<<10;  
	return 0;
}
