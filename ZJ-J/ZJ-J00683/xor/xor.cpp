#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[500011];
ll qzh[500011];
ll ans;
ll k;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)
		qzh[i]=qzh[i-1]^a[i];
	ll l=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=l+1;j<=i;j++)
		{
			if((qzh[i]^qzh[j-1])==k)
			{
				//cout<<i<<" "<<j<<" "<<qzh[i]<<" "<<qzh[j-1]<<" "<<*qzh[i]^qzh[j-1])<<endl;
				ans++;
				l=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
//dark_knight_ak_all
//lcfollower
//huyao
//qzh120124
//hhztl
//wangchuyue
//b1tset
//robin_kool
//cosm0s
//dream_stars
//dream_sky
//xxxyz
//bjxxzjh
//heyechen
//a_tall_bird
//xsj4zyc
//yaozhuocheng
//Xrange
//lzy
//autumn_kite
//ymq I love you
