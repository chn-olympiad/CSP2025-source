#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ca(ll x,ll y)
{
	ll ans=1,q=y;
	for(ll i=x; i<=y; i++)
	{
		ans=ans*q;
		q--;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll x=0;
	for(ll i=0; i<n; i++)
	{
		ll t;
		cin>>t;
		if(t==1) x++;
	}
	if(x>m) cout<<ca(m,x);
	if(x==m)cout<<ca(x,x);
	if(x<m) cout<<0;
	return 0;
}
