#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e5+10;
ll n,t;
ll dp[N][4];
ll a[N][3],shu[N][3];
ll ans1=0,ans2=0,ans3=0;
int main()
{
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t>0)
	{
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			
		}
		
		
		
			dp[1][1]=a[1][1];
			dp[1][2]=a[1][2];
			dp[1][3]=a[1][3];
		for(int i=2;i<=n;i++)
		{
			
			shu[i][1]=n/2;
			shu[i][2]=n/2;
			shu[i][3]=n/2;
			ll js=3;
				for(int j=1;js>=1;j++)
				{
					
					if(js!=1)
					{
						if(shu[i][j]>0)
						{
							
							if(dp[i][js]<dp[i-1][js]+a[i][j])
							{
								dp[i][js]=dp[i-1][js]+a[i][j];
								shu[i][j]--;
							}
							else
							{
								dp[i][js]=dp[i][js];
								shu[i][j]=shu[i][j];
							}
							
							if(j+1>3)
							{
								j=0;
								js--;
								shu[i][1]=n/2;
								shu[i][2]=n/2;
								shu[i][3]=n/2;
							}
						
							continue;
						}
						
						if(shu[i][j]==0)
						{
							
							if(dp[i][js]<dp[i-1][js])
							{
								dp[i][js]=dp[i-1][js];
								shu[i][j]++;
								
							}
							else
							{
								dp[i][js]=dp[i][js];
								shu[i][j]++;
								
							}
							
							if(j+1>3)
							{
								j=0;
								js--;
								shu[i][1]=n/2;
								shu[i][2]=n/2;
								shu[i][3]=n/2;
							}
							continue;
						}
					}
					
					if(js==1)
					{
						if(shu[i][j]>0)
						{
							
							if(dp[i][js]<dp[i-1][js]+a[i][j])
							{
								dp[i][js]=dp[i-1][js]+a[i][j];
								shu[i][j]--;
							}
							else
							{
								dp[i][js]=dp[i][js];
								shu[i][j]=shu[i][j];
							}
							
							if(j+1>3)
							{
								dp[i][js]=max(max(dp[i][js],dp[i][js+1]),dp[i][js+2]);
								break;
							}
						
						}
						if(shu[i][j]==0)
						{
							
							if(dp[i][js]<dp[i-1][js])
							{
								dp[i][js]=dp[i-1][js];
								shu[i][j]++;
								
							}
							else
							{
								dp[i][js]=dp[i][js];
								shu[i][j]++;
								
							}
							
							if(j+1>3)
							{
								dp[i][js]=max(max(dp[i][js],dp[i][js+1]),dp[i][js+2]);
								break;
							}
							
						}
						
					}
					
					
				}
				
				
			
			
		}
		
		cout<<dp[n][3]<<"\n";
		t--;
	}
	
	
	
	
	
	
	return 0;
}

