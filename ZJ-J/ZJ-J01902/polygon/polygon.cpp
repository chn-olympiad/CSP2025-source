#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e3+10;
const int m=5e3+1;
const ll mod=998244353;

ll dp[N];
int a[N],n;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=m;j++) ans=(ans+dp[j])%mod;
		for(int j=m;j>=0;j--) dp[min(j+a[i],m)]=(dp[min(j+a[i],m)]+dp[j])%mod;
	}
	cout << ans << '\n';
	return 0;
}
