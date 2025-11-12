#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+6;
ll c[N];
const int MOD=998244353;
ll jie(ll n)
{
	ll ans=1;
	for (ll i = 1;i <= n;i++)
	{
		ans=ans*i%MOD;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	string s;
	cin >> s;
	ll num=0;
	for (ll i = 0;i < n;i++)
	{
		if (s[i]=='1')
		{
			num++;
		}
	}
	for (ll i = 1;i <= n;i++)
	{
		scanf("%lld",&c[i]); 
	}
	if (m==1)
	{
		if (num>=1)
		{
			printf("%lld",jie(n));
		}
		else
		{
			printf("%lld",(ll)0);
		}
	}
	if (m==n)
	{
		if (num==n)
		{
			printf("%lld",jie(n));
		}
		else
		{
			printf("%lld",0);
		}
	}
	if (num==n)
	{
		printf("%lld",jie(n));
	}
	return 0;
}

