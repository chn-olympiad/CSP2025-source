#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=510,mod=998244353;
int dp[N][N][N],s[N],n,c[N],m,sum[N];
int cnt[N];
int fac[N],inv[N];
int pw(int a,int b){
	if(!b)return 1;
	if(b&1)return pw(a*a%mod,b>>1)%mod*a%mod;
	return pw(a*a%mod,b>>1)%mod;
}
int C(int i,int j){
	if(i<0||j<0||i<j)return 0;
	return fac[i]*inv[j]%mod*inv[i-j]%mod;
}
int A(int i,int j){
	if(i<0||j<0||i<j)return 0;
	return fac[i]*inv[i-j]%mod;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	inv[n]=pw(fac[n],mod-2)%mod;
	for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;init();
	for(int i=1;i<=n;i++){
		char x;cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i],cnt[c[i]]++;
	sum[0]=cnt[0];
	for(int i=1;i<=n;i++)sum[i]=cnt[i]+sum[i-1];
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			for(int j=0;j<i;j++)
			for(int k=0;k<i;k++){
				dp[i][j+1][k]=(dp[i][j+1][k]+dp[i-1][j][k])%mod;
				//用了一个耐心<=i-1-j的人 
				int r=i-1-j;
				for(int w=0;w<=cnt[r+1]&&k+1+w<=i;w++)dp[i][j][k+1+w]=(dp[i][j][k+1+w]+dp[i-1][j][k]*(sum[r]-k)%mod*A(i-1-k,w)%mod*C(cnt[r+1],w)%mod)%mod;
			}
		}
		else{
			for(int j=0;j<i;j++)
			for(int k=0;k<i;k++){
				int r=i-1-j;
				//用了一个耐心<=i-1-j的人
				for(int w=0;w<=cnt[r+1]&&k+1+w<=i;w++)dp[i][j][k+1+w]=(dp[i][j][k+1+w]+dp[i-1][j][k]*(sum[r]-k)%mod*A(i-1-k,w)%mod*C(cnt[r+1],w)%mod)%mod;
				//否则
				for(int w=0;w<=cnt[r+1]&&k+w<=i;w++)dp[i][j][k+w]=(dp[i][j][k+w]+dp[i-1][j][k]*A(i-k,w)%mod*C(cnt[r+1],w)%mod)%mod;
			}
		}
	}
	int ans=0;
	for(int j=m;j<=n;j++)
		for(int k=0;k<=n;k++){
			int sum=0;
			for(int p=n-j+1;p<=n;++p)sum+=cnt[p];
			if(sum==n-k)ans=(ans+dp[n][j][k]*fac[sum]%mod)%mod;
		}
	cout<<ans<<endl;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

4 3
1011
4 4 4 0
*/
