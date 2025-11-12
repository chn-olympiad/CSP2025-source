/*
	SN-J00158 
	华紫陌
	西安辅轮中学 
*/
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,k;
int a[500001];
int s[500001];
int dp[500001];
int cal(int x,int y)
{
	return s[x-1]^s[y];
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(cal(j,i)==k) dp[i]=max(dp[i],dp[j-1]+1);
			else dp[i]=max(dp[i],dp[j-1]);
	cout<<dp[n];
	return 0;
}
