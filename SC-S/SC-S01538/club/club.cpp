#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl '\n'
using namespace std;
const int maxn=200+5;
int a[maxn],b[maxn],c[maxn],dp[maxn][maxn][maxn];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp,-0x3f,sizeof(dp));
	int t;cin>>t;
	while(t--)
	{
		int n,ans=0;cin>>n;
		if(n<=200)
		{
			for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2;k++)
					{
						dp[i][j][k]=-inf;
						int l=i-j-k;
						if(l<0||l>n/2) continue;
						if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]);
						if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+b[i]);
						if(l>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+c[i]);
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				int x,y,z;cin>>x>>y>>z;
				ans+=x;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
