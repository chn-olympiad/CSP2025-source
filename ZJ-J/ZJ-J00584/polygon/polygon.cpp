#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
int n,a[5001],b[5001],dp[501][50001],ans=0,fact[5001];
void solve(){
	int res=1;
	for(int i=1;i<=n;i++){
		res*=2;
		res%=P;
	}
	res-=1;
	res-=n;
	res-=(n*(n-1)/2);
	cout<<res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500){
		solve();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	dp[1][a[1]]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b[i];j++){
			if(i==1 and j==a[1])continue;
			dp[i][j]=dp[i-1][j-a[i]]%P+dp[i-1][j]%P;
			if(a[i]==j)dp[i][j]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=b[i-1];j++){
			ans+=dp[i-1][j];
			ans%=P;
		}
	}
	cout<<ans%P;
	return 0;
}
