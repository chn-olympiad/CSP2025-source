#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505;
const ll M=998244353;
ll n,m;
char c[N];
ll one[N];
ll pa[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr);
	one[0]=0;
	cin>>n>>m;
	ll x=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]=='1')
		{
		    x++;
			one[x]=i; 	
		}
	}
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		pa[a]++;
	}
	ll out=0;
	for(ll i=1;i<=n;i++)
	{
		ll place=one[i]-one[i-1];
		out+=abs(max(place-pa[i],0));
		out++;
	}
	if(n-out<m) cout<<0;
	else if(n-out==m) cout<<1; 
	else
	{
		ll ans=out;
		for(ll i=m;i<=n-out;i++)
		{
			ans*=
		}
	}
	return 0;
}
