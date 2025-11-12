#include<bits/stdc++.h>
using namespace std;
int T;
int n,ans;
int wi[100010][5];
int sum1[100010];
int sum2[100010];
int dp[8010][8010];
bool flag1=true;
bool flag2=true;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>wi[i][1]>>wi[i][2]>>wi[i][3];
			if(wi[i][2]!=0||wi[i][3]!=0)
			{
				flag1=false;
			}
		}
		if(flag1==true)
		{
			for(int i=1;i<=n;i++)
			{
				sum1[i]=wi[i][1];
			}
			sort(sum1+1,sum1+1+n);
			for(int i=n/2+1;i<=n;i++)
			{
				ans+=sum1[i];
			}
			cout<<ans<<"\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{//员工 并且每个员工都需要安排
				for(int j=min(n/2,i-1);j>=0;j--)
				{
					for(int k=min(n/2,i-1);k>=0;k--)
					{
						if(i-j-k-1<0)
						{
							continue;
						}
						dp[j+1][k]=max(dp[j+1][k],dp[j][k]+wi[i][1]);//放在第一个部门
						dp[j][k+1]=max(dp[j][k+1],dp[j][k]+wi[i][2]);//放在第二个部门
						dp[j][k]=max(dp[j][k],dp[j][k]+wi[i][3]);//放在第三个部门
					}
				}//需要从大到小枚举  不然会互相影响
			}
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					if(j+k<n/2)
					{
						continue;
					}
					ans=max(ans,dp[j][k]);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
