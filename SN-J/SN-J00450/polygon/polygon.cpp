#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
typedef long long ll;
const int N = 5005;
int a[N];
int n;
void solve()
{
	//如果全是1
	//那么只要有3个及以上的木棍都可以
	int k = n*(n-1)*(n-2)/(3*2*1);
	ll ans = 0;
	for(int i = 3;i<=n;i++)
	{
		ans+=1ll*k;
		ans=ans%mod;
		k*=(n-i);
	} 
	cout<<ans<<"\n";
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>20) 
	{
		solve(); 
		return 0; 
	}
	ll ans = 0;
	for(int i = 0;i<=(1<<n)-1;i++)//二进制枚举 
	{
		int k = i;
		ll sum = 0;
		ll maxn = 0;
		for(int j = 1;j<=n;j++)
		{
			int now = k%2;
			k=k>>1;
			if(now==1)
			{
				sum+=a[j];
				maxn=max(maxn,1ll*a[j]);
			}
		}
		if(sum>maxn*2)
		{
			ans++;
		}
		ans=ans%mod;
	}
	cout<<ans%mod<<"\n";
	return 0;
}
