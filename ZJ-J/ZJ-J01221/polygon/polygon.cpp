#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int MOD=998244353;
int a[N];
int dp[N*N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		int mx=a[i],rec=0;
		for(int k=max(1,i-1);k<i;k++){
			for(int j=sum;j>=0;j--)if(dp[j]!=0){
				dp[j+a[k]]=(1LL*dp[j+a[k]]+dp[j])%MOD;
				sum=max(sum,j+a[k]);
			}
		}	
		for(int j=mx+1;j<=sum;j++)ans=(1LL*ans+dp[j])%MOD;  
	}
	cout<<ans;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}