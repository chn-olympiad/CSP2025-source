#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans;
int a[500001],sum[500001],dp[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			if((sum[i]^sum[j-1])==k)
				dp[i]=max(dp[i],dp[j-1]+1);
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}