#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n,m;
ll mp[110];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=(n*m);++i) cin>>mp[i];
	ll r=mp[1]; 
	sort(&mp[1],&mp[n*m+1]);
	ll wh=0;
	for(ll i=(n*m);i>=1;--i)
	{
		if(mp[i]==r)
		{
			wh=n*m-i+1;
			break;
		}
 	}
 	ll lie=(wh+n-1)/n;
 	if(lie%2==1)
 	{
 		ll cha=n+wh-lie*n;
 		cout<<lie<<" "<<cha;
	}
	else
	{
		ll cha=lie*n-wh+1;
		cout<<lie<<" "<<cha;
	}
	return 0;
}