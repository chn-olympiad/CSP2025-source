#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
ll n,a[101];
bool use[101];
ll fh;
ll f[5011][5011];
ll ans=0;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		for(ll i=0;i<=(1<<n);i++)
		{
			ll t=i;
			for(ll j=1;j<=n;j++)use[j]=0;
			ll ans=0;
			ll sum=0;
			while(t)
			{
				sum++;
				if(t%2)
				{
					ans++;
					use[sum]=1;
					//cout<<sum<<" ";
				}
				t=t/2;
			}
			if(ans<3)continue;
			ll num=0,maxn=0;
			for(ll j=1;j<=n;j++)
			{
				if(use[j])
				num+=a[j],maxn=max(maxn,a[j]);
			}
			if(num>2*maxn)
			{
				fh=(fh+1)%mod;
			}
		}
		cout<<fh%mod;
		return 0;
	}
	else{
		f[1][1]=1;
		f[2][1]=1;
		f[2][2]=2;
		f[2][3]=1;
		for(ll i=3;i<=n+1;i++)
			for(ll j=1;j<=n+1;j++)
			{
				f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
			}
		/*for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)cout<<f[i][j]<<" ";
			cout<<endl;
		}*/
		for(ll i=4;i<=n+1;i++)
		ans=(ans+f[n][i])%mod;
		cout<<ans%mod;
		return 0;
	}
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
