#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],sum[N],r[N],dp[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=max(i,r[i-1]+1);j<=n;j++)
			if((sum[j]^sum[i-1])==k){
				r[i]=j;
				break;
			}
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
		if(r[i])dp[r[i]]=max(dp[r[i]],dp[i]+1);
	}for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
