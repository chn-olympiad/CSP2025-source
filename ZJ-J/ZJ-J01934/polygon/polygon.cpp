#include<bits/stdc++.h>
#define int long long
//#define pqg priority_queue<int,vector<int>,greater>
//#define pql priority_queue<int,vector<int> >
using namespace std;
int n,ans;
int a[5005];
int dp[5005];
const int N=998244353;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		int dp[5005]={0},b[5005]={0};
		for(int j=1;j<=i-1;j++)
		{
			for(int k=a[i]+1;k>=0;k--)
			{
				dp[k]=dp[k]%N;
				if(dp[k]!=0)
				{
					if(k+a[j]>a[i])dp[a[i]+1]+=dp[k];
					else dp[k+a[j]]+=dp[k];
				}
				dp[a[i]+1]=dp[a[i]+1]%N;
				dp[k+a[j]]=dp[k+a[j]]%N;
				if(b[k]!=0)
				{
					if(k+a[j]>a[i])dp[a[i]+1]+=b[k];
					else dp[k+a[j]]+=b[k];
				}
				dp[a[i]+1]=dp[a[i]+1]%N;
				dp[k+a[j]]=dp[k+a[j]]%N;
				if(k==0)b[a[j]]++;
				b[a[j]]=b[a[j]]%N;
			}
		}
		ans+=dp[a[i]+1];
		ans=ans%N;
	}
	cout<<ans;
	return 0;
}
