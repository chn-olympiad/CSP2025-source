#include<bits/stdc++.h>
#define int long long
#define Ms(shuzu,val) memset(shuzu,val,sizeof(shuzu))
#define Exit(str,val) {cout<<str<<endl;return val;}
using namespace std;
const int N=5e5+5,mod=998244353;
int a[N],s[N],dp[505][50005];
//qian i gen xiao mu gun,chang du he wei j,neng ping chu de fang an shu
//  
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;int max0=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],max0=max(max0,a[i]),s[i]=s[i-1]+a[i];
	sort(a+1,a+n+1);
	if(max0==1) Exit(n-2,0)
	else if(n<=25)
	{
		int ans=0;
		for(int xx=0;xx<(1<<n);xx++)
		{
			int maxx=0,sum=0;
			for(int i=1;i<=n;i++)
				if(xx&(1<<(i-1)))
					maxx=max(maxx,a[i]),sum+=a[i];
			if(sum>2*maxx) ans++;
		}
		cout<<ans%mod<<endl;
	}
	else if(n<=500)
	{
		int ans=0;
		for(int i=0;i<=n;i++) dp[i][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=2*a[i]+1;j<=s[i];j++)
				dp[i][j]=dp[i-1][j-a[i]]+1;
		for(int i=1;i<=n;i++)
			for(int j=2*a[i]+1;j<=s[i];j++)
				ans=(ans+dp[i][j])%mod;
		cout<<ans<<endl;
	}
	return 0;
}