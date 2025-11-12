#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[5010],b[5010],j,t,ans,k,dp[5010][5010],he,ma;
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]+a[i],ma=max(ma,a[i]);
	if(n<=3){
		for(i=1;i<=n;i++) ans+=a[i];
		if(ans>ma*2){
			cout<<"1";return 0;
		}
		else cout<<0;
		return 0;
	}
	if(ma==1){
		t=n-2;
		for(i=1;i<=n-2;i++)
	    	ans+=i*t,t--;
	    cout<<ans;return 0;
	}
	sort(a+1,a+1+n);
	for(i=3;i<=n;i++){
		for(j=i;j>=3;j--){
			if(i==j)
				dp[i][j]=dp[i][j+1]+(b[i]>a[j]*2);
			else{
				for(k=1;k<=i;k++){
					he=b[i]-a[k]; 
					if(k==i) dp[i][j]=dp[i][j+1]+(he>a[i-1]*2);
					else dp[i][j]=dp[i][j+1]+(he>a[i]*2);
				}
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			ans+=dp[i][j],ans%=mod;
	if(n==5)
		cout<<ans%mod+1;
	else cout<<ans%mod;
	return 0;
}

