#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[5010],sum[5010],j,ans,f[510][50010],dp[5010][5010];
const int mo=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	cout<<(sizeof(f)+sizeof(dp))/1024/1024;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	if(n<=500){
		f[0][0]=1;
		for(i=1;i<=n;i++)
			for(j=0;j<=sum[i];j++){
				f[i][j]=f[i-1][j];
				if(j>=a[i])f[i][j]+=f[i-1][j-a[i]],f[i][j]%=mo;
			}
		for(i=3;i<=n;i++)
			for(j=a[i]+1;j<=sum[i-1];j++)ans+=f[i-1][j],ans%=mo;
		cout<<ans;
	}
	else {
		dp[0][0]=1;
		for(i=1;i<=n;i++)
			for(j=0;j<=sum[i];j++){
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])dp[i][j]+=dp[i-1][j-a[i]],dp[i][j]%=mo;
			}
		for(i=3;i<=n;i++)
			for(j=a[i]+1;j<=sum[i-1];j++)ans+=dp[i-1][j],ans%=mo;
		cout<<ans;
	}
	return 0;
}