#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int a[5010];
const int mod=998244353;
int dp[5010];
int sum[5010];
int maxn[5010];
int minn[5010];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(minn,0x3f,sizeof(minn));
	cin>>n;
	int maxa=-1e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]);
		sum[i]=sum[i-1]+a[i];
		maxn[i]=maxa;
		minn[i]=min(minn[i-1],a[i]);
	}
	for(int i=n;i>=3;i--)
	{
		int cnt=1;
		int j=1;
		while(cnt<3&&j<=i-1)
		{
			if(minn[i-j]!=minn[i])
			{
				cnt++;
				minn[i]=minn[i-1];
			}
			j++;
		}
	}
	dp[0]=1;
	for(int i=3;i<=n;i++)//qian i gen gan zi
	{
		for(int j=sum[i];j>=minn[i]*2;j--)//chang du he xian zhi
		{
			dp[j]=(dp[j]+dp[j-minn[i]*2])%mod;
		}
	}
	cout<<dp[n];
	return 0;
}
