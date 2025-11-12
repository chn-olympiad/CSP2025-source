#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000;
int n,k;
int a[MAXN+5];
int cnt;
int s[MAXN+5];
int dp[MAXN+5],f[MAXN+5];
//dp[i]:a1~ai可以构成多少个区间 
//f[i]:dp[1]~dp[i]的最大值 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	//cout<<'\n';
	//s[r]^s[l-1]=s[l]^s[l+1]^s[l+2]^...^s[r]
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		for(int l=i;l>=1;l--)
		{
			dp[i]=max(dp[i],f[l-1]+((s[i]^s[l-1])==k));
		}
		f[i]=max(f[i-1],dp[i]);
	}
	cout<<dp[n];
	return 0;
}

