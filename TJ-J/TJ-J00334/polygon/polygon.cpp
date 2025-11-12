#include<iostream>
#include<algorithm>
using namespace std;
long long ans=0;
long long n,q,a[5005],x,sum[5005];
int dp[5005][50005];
int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum[i];j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]){
				dp[i][j]+=dp[i-1][j-a[i]];
				dp[i][j]%=mod;
			}
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=sum[i-1];j++){
			ans+=dp[i-1][j];
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
