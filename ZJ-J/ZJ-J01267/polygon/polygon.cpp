#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[5010],ans,j,k,h[510],lst,dp[510][50010],e[510][50010];
const int mod=998244353;
void dg(int t,int s,int ss,int sss){
	if(t==n+1){
		if(s>=3&&ss>a[sss]*2) ans=(ans+1)%mod;	
		return ;
	}
	dg(t+1,s,ss,sss);
	dg(t+1,s+1,ss+a[t],t);
}
bool check(){
	int i;
	for(i=1;i<=n;i++)
		if(a[i]!=1) return 0;
	return 1; 
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		sort(a+1,a+1+n);
		dg(1,0,0,0);cout<<ans;return 0;
	}
	if(check()){
		ans=1;
		for(i=1;i<=n;i++) ans=ans*2%mod;
		ans=(ans-1+mod)%mod;
		ans=(ans-n+mod)%mod;
		ans=(ans-n*(n-1)/2%mod+mod)%mod;
		cout<<ans;return 0;
	}
	if(n<=500){
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++) h[i]=h[i-1]+a[i];
		dp[0][0]=1;e[0][0]=1;
		for(i=1;i<=n;i++){
			for(j=0;j<=i;j++)
				for(k=0;k<=201;k++) dp[j][k]=0;
			for(j=0;j<=i-1;j++)
				for(k=0;k<=201;k++)
					if(k+a[i]<=201)
						dp[j+1][k+a[i]]=(dp[j+1][k+a[i]]+e[j][k])%mod;
					else dp[j+1][201]=(dp[j+1][201]+e[j][k])%mod;
			for(j=0;j<=i;j++)
				for(k=0;k<=201;k++) e[j][k]=(e[j][k]+dp[j][k])%mod;
			for(j=3;j<=i;j++)
				for(k=2*a[i]+1;k<=201;k++) ans=(ans+dp[j][k])%mod;
		}
		cout<<ans;return 0;
	}
	return 0;
}