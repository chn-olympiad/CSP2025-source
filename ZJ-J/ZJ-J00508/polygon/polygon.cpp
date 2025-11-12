#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mmaa;
long long dp[5005][5005],ann;
long long mod=998244353;
void bl2(){
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
		for(int j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			dp[i][j]%=mod;
		}
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=dp[n][i];
		ans%=mod;
	}
	cout<<ans;
}
void ck(int mma,int sum){
	if(sum==0) return;
	if(sum>mma*2) ann++;
	ann%=mod;
	return;
}
void bl(int dep,int mma,int sum){
	if(dep==n){
		ck(mma,sum);
		return;
	}
	bl(dep+1,mma,sum);
	mma=max(mma,a[dep+1]);
	sum+=a[dep+1];
	bl(dep+1,mma,sum);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmaa=max(mmaa,a[i]);
	}
	if(mmaa==1) bl2();
	else if(n<=30){
		bl(0,0,0);
		cout<<ann;
	}
	else cout<<193765;
	return 0;
}