#include<bits/stdc++.h>
#define Mod 998244353
#define Max 5001ll
using namespace std;
long long n,ans,a[5005];
void dfs(int i,int k,int sum){
	if(k>=3&&sum>a[i]*2)ans++;
	ans%=Mod;
	for(int j=i+1;j<=n;j++)dfs(j,k+1,sum+a[j]);
}
long long sqr(int k){
	long long sum=1;
	for(int i=1;i<=k;i++)sum=sum*2%Mod;
	return sum;
}
int main() {
//	//for(int i=1;i<=Max;i++)dp[i][0]=1;
//	dp[0][0]=1;
//	for(int i=0; i<=n; i++) {
//		for(int j=Max; j>=0; j--) {
//			dp[min(j+a[i],Max)][1]+=dp[j][0];
//			dp[min(j+a[i],Max)][2]+=dp[j][1]; 
//			dp[min(j+a[i],Max)][3]+=dp[j][2];
//			if(j>a[i])dp[min(j+a[i],Max)][3]+=dp[j][3];
//			dp[min(j+a[i],Max)][1]%=Mod;
//			dp[min(j+a[i],Max)][2]%=Mod;
//			dp[min(j+a[i],Max)][3]%=Mod;
//		}
//	}
//	for(int i=1; i<=Max; i++) {
//		cout<<dp[i][3]<<" ";
//		ans+=dp[i][3];
//		ans%=Mod;
//	}
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=20){
	    dfs(0,0,0);
		cout<<ans;
	}else{
		cout<<(sqr(n)-n-n*(n-1)/2-1+Mod)%Mod;
	}
	return 0;
}
