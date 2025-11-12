#include<bits/stdc++.h>
using namespace std;
char s[510];
int cnt[510],sum[510];
int dp[510][510][510],fac[510],inv[510];
const int mod=998244353;
int c(int i,int j){
	if(j<0||j>i)return 0;
	return 1ll*fac[i]*inv[j]%mod*inv[i-j]%mod;
}
int p(int i,int j){
	int ans=1;
	while(j){
		if(j%2)ans=1ll*ans*i%mod;
		j>>=1;
		i=1ll*i*i%mod;
	}
	return ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m>>(s+1);
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<=n;i++)inv[i]=p(fac[i],mod-2);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	sum[0]=cnt[0];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+cnt[i];
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=sum[j]&&k<=i;k++){
				if(!dp[i][j][k])continue;
				if(s[i+1]=='0'){
					for(int l=0;l<=cnt[j+1];l++){
						if(k+l+1>n)break;
						dp[i+1][j+1][k+l]=(dp[i+1][j+1][k+l]+1ll*dp[i][j][k]*c(i-k,l)%mod*c(cnt[j+1],l)%mod*fac[l])%mod;
						dp[i+1][j+1][k+l+1]=(dp[i+1][j+1][k+l+1]+1ll*dp[i][j][k]*c(i-k,l)%mod*c(cnt[j+1],l)%mod*fac[l]%mod*(cnt[j+1]-l))%mod;
						dp[i+1][j+1][k+l+1]=(dp[i+1][j+1][k+l+1]+1ll*dp[i][j][k]*c(i-k,l)%mod*c(cnt[j+1],l)%mod*fac[l]%mod*max(sum[j]-k,0))%mod;
					}
				}else{
					dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%mod;
					for(int l=0;l<=cnt[j+1];l++){
						if(k+l+1>n)break;
						dp[i+1][j+1][k+l+1]=(dp[i+1][j+1][k+l+1]+1ll*dp[i][j][k]*c(i-k,l)%mod*c(cnt[j+1],l)%mod*fac[l]%mod*max(sum[j]-k,0))%mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++){
		ans=(ans+1ll*dp[n][i][sum[i]]*fac[n-sum[i]])%mod;
	}
	cout<<ans;
	return 0;
}

