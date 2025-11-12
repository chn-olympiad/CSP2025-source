#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],dp[N][2],sum[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum[i]=a[i];
		if(a[i]==k)
		{
			dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
			dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
		}
		else
		{
			dp[i][1]=max(dp[i][1],dp[i-1][0]);
			dp[i][0]=max(dp[i][0],dp[i-1][0]);
		}
		for(int j=1;j<i;j++)
		{
			if(sum[j]!=k)
			{
				sum[j]=sum[j]^a[i];
				if(sum[j]==k)
				{
					dp[i][0]=max(dp[i][0],dp[j][1]+1);
				}
			}
		}	
	}
	//for(int i=1;i<=n;i++) cout<<i<<":"<<dp[i][0]<<" "<<dp[i][1]<<endl;
	cout<<max(dp[n][0],dp[n][1])<<endl;
	return 0;
}
/*
int a=2;
int b=3;
int c=0;
a=a^b^c;
cout<<a<<endl;
*/
