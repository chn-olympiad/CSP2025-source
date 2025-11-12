#include<bits/stdc++.h>

using namespace std;

const int N=5e3+5;
const long long mod=998244353;

int n,mx;

int a[N];

long long dp[N][N];
long long ans;

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	
	sort(a+1,a+1+n);
	
	dp[0][0]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=mx;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]&&dp[i-1][j-a[i]]!=0){
				dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
			}
//			cout<<dp[i][j]<<" ";
		}
		dp[i][mx+1]=dp[i-1][mx+1];
		for(int j=mx-a[i]+1;j<=mx+1;j++){
			if(dp[i-1][j]!=0){
				dp[i][mx+1]=(dp[i][mx+1]+dp[i-1][j])%mod;
			}
		}
//		cout<<dp[i][mx+1];
//		cout<<"\n";
	}
	
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=mx+1;j++){
			ans=(ans+dp[i-1][j])%mod;
		}
	}
	
	cout<<ans;
	
	return 0;
}

/*
5
1 2 3 4 5


*/