#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int q[N][4];
int n;
int dp[N][N];
int ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt;
	cin>>ttt;
	int k;
	while(ttt--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)
		{
			cin>>q[i][j];
			//cout<<q[i][j]<<' ';
			//q[i][j]*=j;
		}
		//cout<<endl;
		memset(dp,0,sizeof(dp));
		for(int ii=1;ii<=n;ii++)
		{
			for(int i=min(n/2,ii);i>=0;i--)for(int j=min(n/2,ii);j>=0;j--)
			{
				//dp[i][j]=0;
				k=ii-i-j;
				if(k>n/2)continue;
				if(k<0)continue;
				if(k>0)
				{
					dp[i][j]=max(dp[i][j]+q[ii][3],dp[i][j]);
				}
				if(i>0)
				{
					dp[i][j]=max(dp[i-1][j]+q[ii][1],dp[i][j]);
				}
				if(j>0)
				{
					dp[i][j]=max(dp[i][j-1]+q[ii][2],dp[i][j]);
				}
				
				
				//cout<<dp[i][j]<<' '<<i<<' '<<j<<' '<<ii<<endl;
				
			}
		}
		ans=0;
		for(int i=0;i<=n/2;i++)for(int j=0;(j+i<=n)&&(j<=n/2);j++)
		{
			if(n-i-j>n/2)continue;
			if(n-i-j<0)continue;
			ans=max(ans,dp[i][j]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
