#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],dp[505][5005][2],s[5005],mx;
int ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
	if(mx==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		int xx=(n+1+n*(n-1)/2)%mod;
		cout<<((ans-xx)%mod+mod)%mod;
		return 0;
	}
	if(n>=500){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			for(int k=s[i]-s[i-j];k>=0;k--){
				if(k-a[i]>a[i]){
					dp[j][k][1]+=(dp[j-1][k-a[i]][0]+dp[j-1][k-a[i]][1])%mod;
					dp[j][k][1]%=mod;
				}
				else if(k-a[i]>=0){
					dp[j][k][0]+=(dp[j-1][k-a[i]][0]+dp[j-1][k-a[i]][1])%mod;
					dp[j][k][0]%=mod;
				}
			}
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=s[n]-s[n-i];j++){
			ans+=(dp[i][j][1]%mod);
			ans%=mod;
		}
	}
	cout<<ans%mod;
}
