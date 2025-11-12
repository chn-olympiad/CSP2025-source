#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],ans,dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		a[i]=a[i]^a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int b=a[j]^a[i];
			if(b==k){
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
