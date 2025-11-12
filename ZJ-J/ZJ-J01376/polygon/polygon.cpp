#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=5000;
int n,a[N],t,s[N*N],ma,ans;
struct node
{
	int zhi,bian;
}dp[N*N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)//以第i条木棒为最长边时 
	{
		 int x=t;
		for(int j=1;j<=x;j++)
		{
			dp[++t].zhi=dp[j].zhi+a[i];
			dp[t].bian=dp[j].bian+1;	
		}
		for(int j=1;j<=t;j++)
		{
//			cout<<a[i]<<" "<<dp[j].bian<<" "<<dp[j].zhi<<endl;
			if(dp[j].bian>=2&&dp[j].zhi>2*a[i])ans=(ans+1)%M;
		}
		dp[++t].zhi=a[i];
		dp[t].bian=1;
	}
	cout<<ans;
	return 0;	
} 
