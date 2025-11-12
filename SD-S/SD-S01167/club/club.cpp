#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=1e2+10;
int a[N][5],dp[N][N][N][N],b[N];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,ans=0;
		cin>>n;

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
			b[i]=a[i][1];
//			cout<<a[i][1]<<a[i][2]<<a[i][3]<<endl; 
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<N;k++)
				{
					for(int l=0;l<N;l++)
					{
						dp[i][j][k][l]=0;		
					}
				}
			}
		}
		if(n<=200)
		{	
			for(int i=1;i<=n;i++)
			{
//				cout<<a[i][1]<<a[i][2]<<a[i][3]<<endl;
				for(int k=0;k<=n/2;k++)
				{
					for(int l=0;l<=n/2;l++)
					{	
						for(int j=0;j<=n/2;j++)
						{
							if(l+k+j>i)	continue;
							if(j==0&&l==0&&k==0)	continue;
							if(l==0)
							{
								if(k==0)
								{
									dp[i][j][k][l]=max(dp[i-1][j][k][l],dp[i-1][j-1][k][l]+a[i][1]);
									continue;
								}
								if(j==0)
								{
									dp[i][j][k][l]=max(dp[i-1][j][k][l],dp[i-1][j][k-1][l]+a[i][2]);
									continue;
								}
								dp[i][j][k][l]=max(dp[i-1][j][k][l],max(dp[i-1][j-1][k][l]+a[i][1],dp[i-1][j][k-1][l]+a[i][2]));
								continue;
							}
							if(k==0)
							{
								if(j==0)
								{
									dp[i][j][k][l]=max(dp[i-1][j][k][l],dp[i-1][j][k][l-1]+a[i][3]);
//									if(l==1)
//									{
//										cout<<a[i][3]<<endl;
//										cout<<dp[i][j][k][l]<<' '<<dp[i-1][j][k][l-1]<<endl;
//									}
									continue;
								}
								dp[i][j][k][l]=max(dp[i-1][j][k][l],max(dp[i-1][j-1][k][l]+a[i][1],dp[i-1][j][k][l-1]+a[i][3]));
								continue;
							}
							if(j==0)
							{
								dp[i][j][k][l]=max(dp[i-1][j][k][l],max(dp[i-1][j][k-1][l]+a[i][2],dp[i-1][j][k][l-1]+a[i][3]));
								if(i==6)
								{
//									cout<<dp[i-1][j][k][l]<<' '<<dp[i-1][j][k-1][l]<<' '<<a[i][2]<<' '<<dp[i-1][j][k][l-1]<<' '<<a[i][3]<<' '<<k<<' '<<l<<' '<<i<<endl;
								}
								continue;
							}
							dp[i][j][k][l]=max(dp[i-1][j][k][l],max(dp[i-1][j][k][l-1]+a[i][3],max(dp[i-1][j][k-1][l]+a[i][2],dp[i-1][j-1][k][l]+a[i][1])));

						}
						for(int j=0;j<=n/2;j++)
						{
							if(l+k+j<=i)
							{
//								cout<<i<<' '<<dp[i][j][k][l]<<' '<<j<<' '<<k<<' '<<l<<endl;
								ans=max(ans,dp[i][j][k][l]); 		
							}						
						}			
					}
				}
			}
			cout<<ans<<endl;
//			continue;
		}
		else
		{
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--)
			{
				ans+=b[i];
			}
			cout<<ans<<endl;		
		}
	}
	return 0;
}
/*
3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
 1
 6
 1 1 2
 1 1 2
 1 1 2
 1 1 2
 1 1 2
 1 1 2
*/
