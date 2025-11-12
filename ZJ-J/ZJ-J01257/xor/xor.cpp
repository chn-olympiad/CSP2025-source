#include<bits/stdc++.h>
using namespace std;
int i,j,n,k,a[1000010],f[1000010],dp[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(k&&!a[i]){
			i--;
			n--;
		}
		f[i]=f[i-1]^a[i];
	}
	for(i=1;i<=n;i++)
		for(j=i;j>=1;j--){
			if(dp[i]>dp[j]&&i-j)
				j=0;
			if(!((f[i]^f[j-1])-k))
				dp[i]=max(dp[i],dp[j-1]+1);
			dp[i]=max(dp[i],dp[j]);
		}
	cout<<dp[n];
}
