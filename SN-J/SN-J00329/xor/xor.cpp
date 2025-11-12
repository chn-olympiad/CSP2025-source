//SN-J00329 zhangjiakang xi'an gaoxindiyizhongxue#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int maxn=5e5+10;
int n,k;
int a[maxn],xorr[maxn],dp[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		xorr[i]=a[i]^xorr[i-1];
	}
	unordered_map<int,int> mp;
//	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(xorr[i]==k)dp[i]=1;
		dp[i]=max(dp[i-1],dp[i]);
		if(mp[xorr[i]^k]==i||mp[xorr[i]^k]==0)
		{
			mp[xorr[i]]=i;
			continue;
		}
		dp[i]=max(dp[i],dp[mp[xorr[i]^k]]+1);
		mp[xorr[i]]=i;
	}
//	for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
	cout<<dp[n];
	return 0;
}
