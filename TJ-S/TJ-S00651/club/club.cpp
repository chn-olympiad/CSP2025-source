#include<bits/stdc++.h>
using namespace std;
int club[100009][3];
int a[100009][4];
int dp[31][31][31][31][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		int ans[9];
		ans[1]=0,ans[2]=0,ans[3]=0; 
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxn==a[i][1])
				ans[1]++,club[ans[1]][1]=i;
			else if(maxn==a[i][2])
				ans[2]++,club[ans[2]][2]=i;
			else if(maxn==a[i][3])
				ans[3]++,club[ans[3]][3]=i;
		}
		int Ans=0;
		if(ans[1]<=n/2&&ans[2]<=n/2&&ans[3]<=n/2)
		{
			for(int i=1;i<=ans[1];i++)
				Ans+=a[club[i][1]][1];
			for(int i=1;i<=ans[2];i++)
				Ans+=a[club[i][2]][2];
			for(int i=1;i<=ans[3];i++)
				Ans+=a[club[i][3]][3];
			cout<<Ans<<endl;
			//continue;
		}
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				//dp[i][1][j]=a[i][j],dp[i][0][j]=0;
				if(j==1)
					dp[i][1][0][0][1]=a[i][j],dp[i][0][0][0][1]=0;
				if(j==2)
					dp[i][0][1][0][2]=a[i][j],dp[i][0][0][0][2]=0;
				if(j==1)
					dp[i][0][0][1][3]=a[i][j],dp[i][0][0][0][3]=0;
				for(int k1=1;k1<=n/2;k1++)
				{
					for(int k2=1;k2<=n/2;k2++)
						for(int k3=1;k3<=n/2;k3++)
						{
							if(j==1)
								dp[i][k1][k2][k3][j]=max(dp[i-1][k1-1][k2][k3][j],max(dp[i-1][k1][k2][k3][2],dp[i-1][k1][k2][k3][3]))+a[i][j];
							if(j==2)
								dp[i][k1][k2][k3][j]=max(dp[i-1][k1][k2-1][k3][j],max(dp[i-1][k1][k2][k3][1],dp[i-1][k1][k2][k3][3]))+a[i][j];
							if(j==3)
								dp[i][k1][k2][k3][j]=max(dp[i-1][k1][k2][k3-1][j],max(dp[i-1][k1][k2][k3][2],dp[i-1][k1][k2][k3][1]))+a[i][j];
							maxn=max(maxn,dp[i][k1][k2][k3][j]);
						}
				}
			}
		}
		//cout<<max(dp[3][1][1],dp[3][1][3])<<endl;
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n/2;j++)
				cout<<dp[i][j][1]<<" "<<dp[i][j][2]<<" "<<dp[i][j][3]<<endl;
			cout<<endl;
		}*/
		cout<<maxn<<endl;	
	}
	return 0;
}
