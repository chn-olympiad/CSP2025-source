#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5005;
const int mx=5005;
int n,s,ans,a[N],dp[mx<<1];
int ksm(int a,int b,int mod){
	int ans=1,base=a;
	while(b){
		if(b&1) ans*=base,ans%=mod;
		base*=base;
		base%=mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s=max(s,a[i]);
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=a[i];j>=0;j--)
			sum+=dp[j],sum%=mod;
		ans+=sum;ans%=mod;
		for(int j=2*s;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
	}
	cout<<((ksm(2,n,mod)-ans-1)%mod+mod)%mod;
	return 0;
}
/*
uid 709361
2025/11/1 11:26:28
passed polygon4.in
FC:找不到差异
I AK CSP-J 2025

2 3 4 5
2 3 4 5 5 6 7 7 8 9 9 10

dp[i][j] dp[i-1][j] dp[i-1][j-a[i]]
*/