#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll c[11][11],b[111],a[111];
bool cmp(ll a,ll b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)cin>>a[i],b[i]=a[i];
	sort(a+1,a+n*m+1,cmp);
	ll i=1,j=1;
	ll cnt=1;
	bool f=0;
	while(cnt<n*m)
	{
		c[i][j]=a[cnt];
		//cout<<i<<" "<<j<<" "<<cnt<<endl;
		cnt++;
		if(!f)
		i++;
		if(f)i--;
		if(i==n)
		{
			//cout<<i<<" "<<j<<" "<<cnt<<endl;
			c[i][j]=a[cnt];
			cnt++;
			j++;
			f=1;
		}
		if(i==1)
		{
			//cout<<i<<" "<<j<<" "<<cnt<<endl;
			c[i][j]=a[cnt];
			cnt++;
			j++;
			f=0;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(c[i][j]==b[1]){
				cout<<j<<" "<<i;
				return 0;
			}
			//cout<<c[i][j]<<" ";
		}
		//cout<<endl;
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
