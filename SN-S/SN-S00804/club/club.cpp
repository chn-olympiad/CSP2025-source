
#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][10],b[100005];
int dp[35][35][35][35];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n>0)
		{
			for(int i=1;i<=n;i++)
			{
					int x,y;
					cin>>b[i]>>x>>y;
				
			}
			sort(b+1,b+1+n);
			int sum=0;
			for(int i=n;i>=n/2+1;i--)
			{
				sum+=b[i];
			}
			cout<<sum;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
				}
			}
			dp[1][1][0][0]=a[1][1];
			dp[1][0][1][0]=a[1][2];
			dp[1][0][0][1]=a[1][3];
			for(int i=2;i<=n;i++)
			{
				for(int j=0;j<=i;j++)
				{
					for(int k=0;k<=i;k++)
					{
						for(int c=0;c<=i;c++)
						{
							if(j+k+c!=i||j>n/2||k>n/2||c>n/2)
							{
								continue;
							}
							if(j>=1)
							{
								dp[i][j][k][c]=max(dp[i][j][k][c],dp[i-1][j-1][k][c]+a[i][1]);
							}
							if(k>=1)
							{
								dp[i][j][k][c]=max(dp[i][j][k][c],dp[i-1][j][k-1][c]+a[i][2]);
							}
							if(c>=1)
							{
								dp[i][j][k][c]=max(dp[i][j][k][c],dp[i-1][j][k][c-1]+a[i][3]);
							}
							//cout<<i<<" "<<j<<" "<<k<<" "<<" "<<c<<" "<<dp[i][j][k][c]<<endl;
						}
					}
				}
			}
			int ans=0;
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2;k++)
					{
						for(int i=0;i<=n/2;i++)
						{
							if(j+k+i==n)ans=max(ans,dp[n][j][k][i]);
							//cout<<dp[n][j][k][i]<<endl;
						}
					}
				}
			cout<<ans<<endl;
			memset(dp,0,sizeof(dp));
		}
	}
	return 0;
}
