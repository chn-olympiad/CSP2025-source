#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int m;
int n;
int a[N];
long long ans=0;
long long dp[N*2];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m=max(a[i],m);
	}
	m++;
	dp[0]=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=m+1;j++)
		ans=(dp[j]+ans)%998244353;
		for(int j=m+1+a[i];j>=a[i];j--)
		{
			dp[min(j,m+1)]+=dp[j-a[i]];
			dp[min(j,m+1)]%=998244353; 
		}
	}
	cout<<ans;
	return 0;
}
