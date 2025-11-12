// by:xt66666
//TYZ
//uid:อüมห 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,m,a[1010];
ll f[110][110];
bool cmp(ll x,ll y)
{
	return x>y;
}
ll fen;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	fen=a[1];
	sort(a+1,a+n*m+1,cmp);
	ll cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=n;j++)
			{
				f[j][i]=a[++cnt];
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				f[j][i]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(f[i][j]==fen)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		} 
	}
	return 0;
}

