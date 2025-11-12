#include<bits/stdc++.h>
using namespace std;
long long n,i,ans,f[5005][5005],dp[10005],a[5005],j,k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(i=1;i<=n;i++){
		f[i][0]=1;
	}
	for(i=1;i<=n;i++){
		f[i][i]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			f[i][j]=f[i-1][j]+f[i-1][j-1];
			f[i][j]%=998244353;
		}
	}
	for(i=3;i<=n;i++){
		ans+=f[n][i];
		ans%=998244353;
	}
	for(i=3;i<=n;i++){
		int s=a[i];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(j=1;j<i;j++){
			for(k=s;k>=a[j];k--){
				dp[k]+=dp[k-a[j]];
			}
		}
		ans+=i-1;
		for(j=1;j<=s;j++){
			ans-=dp[j];
			if(ans<0)ans+=998244353;
		}
	}
	cout<<ans%998244353;
}
