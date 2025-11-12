#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int t;
int n;
int a[1000005][3];
int dp[2][55][55][55];
int x[1000005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool f=0;
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]!=0||a[i][1]!=0)f=1;
			else
			{
			    
				x[i]=a[i][2];
				
			}
			
		}
		if(!f)
		{
			sort(x+1,x+n+1);
			int ans=0;
			for(int i=n;i>=n-n/2;i++)
			{
				ans+=x[i];
			}
			cout<<ans;
			return 0;
		}
		int ans=-1e18;
		for(int i=1;i<=n;i++)
		{
			for(int j=n/2;j>=0;j--)
			{
				for(int k=n/2;k>=0;k--)
				{
					for(int l=n/2;l>=0;l--)
					{
						//cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]<<endl;;
						int tmp=-1e18;
						if(j<n/2)
						tmp=max(dp[(i-1)%2][j+1][k][l]+a[i][0],tmp);
						if(k<n/2)
						tmp=max(dp[(i-1)%2][j][k+1][l]+a[i][1],tmp);
						if(l<n/2)
						tmp=max(tmp,dp[(i-1)%2][j][k][l+1]+a[i][2]);
						dp[i%2][j][k][l]=max(dp[i%2][j][k][l],tmp);
						
						if(i==n&&j+k+l==0)
						{
							ans=max(ans,dp[i%2][j][k][l]);
							
						}
						
					}
				}
			}
		}
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					for(int l=0;l<=n/2;l++)
					{
						dp[0][j][k][l]=0;
						dp[1][j][k][l]=0;
					}
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
