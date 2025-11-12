#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5010];
long long dp[20010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ma=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
	}
	ma=ma*2+1;
	sort(a+1,a+n+1);
	dp[0]=1;
	int mx=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=mx;j>a[i];j--){
			ans+=dp[j];
		}
		ans%=mod;
		for(int j=mx;j>=ma-a[i];j--){
			dp[ma]+=dp[j];
		}
		dp[ma]%=mod;
		for(int j=min(mx,ma-a[i]-1);j>=0;j--){
			dp[j+a[i]]+=dp[j];
			if(dp[j+a[i]]>=mod){
				dp[j+a[i]]-=mod;
			}
		} 
		mx=min(mx+a[i],ma);
	}
	cout<<ans;
	return 0;
} 
