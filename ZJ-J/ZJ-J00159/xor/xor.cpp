#include<bits/stdc++.h>
using namespace std;
int dp[500010];
int sumxor[500010];
int n,k;
unordered_map<int,vector<int>> v;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	v[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		sumxor[i]=sumxor[i-1]^x;
		v[sumxor[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(v.find(sumxor[i]^k) == v.end())
		{
			continue;
		}
		int kk=lower_bound(v[sumxor[i]^k].begin(),v[sumxor[i]^k].end(),i)-v[sumxor[i]^k].begin()-1;
		if(kk == -1)
		{
			continue;
		}
		dp[i]=max(dp[i],dp[v[sumxor[i]^k][kk]]+1);
	}
	cout<<dp[n];
	return 0;
}
