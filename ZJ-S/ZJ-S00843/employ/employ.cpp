#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
char c[510];
int a[510];
int dp[300010][19];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,x;
	ll ans=0,a0=0,c0=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			c0++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			a0++;
		}
	}
	if(n<=18){
		dp[0][0]=1;
		for(int i=0;i<(1<<n)-1;i++){
			x=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					x++;
				}
			}
			for(int j=1;j<=n;j++){
				if(!(i&(1<<(j-1)))){
					//cout<<i<<" "<<(i^(1<<(j-1)))<<" "<<x<<"\n";
					for(int k=0;k<=x;k++){
						if(c[x+1]=='0'){
							dp[i^(1<<(j-1))][k+1]+=dp[i][k];
							//cout<<(i^(1<<(j-1)))<<" "<<i<<" "<<k<<" "<<dp[i][k]<<"x\n";
							dp[i^(1<<(j-1))][k+1]%=mod;
						}else{
							if(k>=a[j]){
								dp[i^(1<<(j-1))][k+1]+=dp[i][k];
								dp[i^(1<<(j-1))][k+1]%=mod;
								//cout<<(i^(1<<(j-1)))<<" "<<i<<" "<<k<<" "<<dp[i][k]<<"y\n";
							}else{
								dp[i^(1<<(j-1))][k]+=dp[i][k];
								dp[i^(1<<(j-1))][k]%=mod;
								//cout<<(i^(1<<(j-1)))<<" "<<i<<" "<<k<<" "<<dp[i][k]<<"z\n";
							}
						}
					}
				}
			}
		}
		for(int i=0;i<=n-m;i++){
			ans=(ans+dp[(1<<n)-1][i])%mod;
		}
		cout<<ans;
	}else if(n==m){
		if(c0==0&&a0==0){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%mod;
			}
		}
		cout<<ans;
	}
	return 0;
}