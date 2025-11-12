#include<bits/stdc++.h>
using namespace std;
long long a[114514][4],b[114514];
long long dp[201][101][101];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,ans=0,q=0,flag=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]!=0)flag=1;
		}
		if(!flag)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][1]-a[i][2];
				ans+=a[i][1];
				
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++)
			{
				ans-=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		dp[0][0][0]=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=0;j<=i&&j<=n/2;j++)
			{
				for(long long k=max((2*i-2*j-n)/2,(long long)(0));k<=n/2&&k<=i-j;k++)
				{
					dp[i][j][k]=0;
					if(j+k!=i)
					{
						dp[i][j][k]=max(dp[i-1][j][k]+a[i][3],dp[i][j][k]);
					}
					if(j!=0)
					{
						dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],dp[i][j][k]);
					}
					if(k!=0)
					{
						dp[i][j][k]=max(dp[i-1][j][k-1]+a[i][2],dp[i][j][k]);
					}
					if(i==n)ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}





