#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5 ;
long long n,k,res;
long long a[maxn],sum[maxn],pre[maxn];
struct node
{
	long long h,id;
};
map<long long,node>mp;
long long dp[maxn][2];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i],sum[i]=sum[i-1]^a[i];
	for(int i=n;i>=1;i--)	pre[i]=pre[i+1]^a[i],mp[pre[i]]={1,i};
	res=sum[n];
	for(int i=1;i<=n;i++)
	{
		long long t;
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(a[i]==k)	dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
		else
		{
			t=k^res^sum[i];
			if(mp[t].h==1)	dp[i][1]=dp[mp[t].id][0]+1;
		}
	}
	cout<<max(dp[n][1],dp[n][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

